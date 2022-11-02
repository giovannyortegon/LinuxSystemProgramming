package main

import (
	"database/sql"
	"fmt"
	"html/template"
	"log"
	"os"

	"net/http"

	_ "github.com/go-sql-driver/mysql"
	"github.com/gorilla/mux"
)

const (
	DBHost  = "127.0.0.1"
	DBPort  = ":3306"
	DBUser  = "test"
	DBPass  = "test1234"
	DBDbase = "cms"
	PORT    = ":8080"
)

var database *sql.DB

type Page struct {
	Title      string
	RawContent string
	// Content string
	Content template.HTML
	Date    string
	GUID    string
}

func main() {
	dbConn := fmt.Sprintf("%s:%s@tcp(%s)/%s", DBUser, DBPass, DBHost, DBDbase)
	db, err := sql.Open("mysql", dbConn)
	if err != nil {
		log.Println("Could not connect.")
		log.Println(err.Error())
		os.Exit(-1)
	} else {
		log.Println("Connect success.")
	}
	database = db

	routes := mux.NewRouter()
	routes.HandleFunc("/page/{guid:[0-9a-zA\\-]+}", ServerPage)
	routes.HandleFunc("/", RedirIndex)
	routes.HandleFunc("/home", ServeIndex)

	http.Handle("/", routes)
	http.ListenAndServe(PORT, nil)
}

func ServerPage(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	pageGUID := vars["guid"]
	thisPages := Page{}

	fmt.Println(pageGUID)

	// err := database.QueryRow("SELECT page_title, page_content, page_date FROM pages WHERE page_guid=?",
	// pageGUID).Scan(&thisPages.Title, &thisPages.Content, &thisPages.Date)
	err := database.QueryRow("SELECT page_title, page_content, page_date FROM pages WHERE page_guid=?",
		pageGUID).Scan(&thisPages.Title, &thisPages.RawContent, &thisPages.Date)
	thisPages.Content = template.HTML(thisPages.RawContent)
	if err != nil {
		http.Error(w, http.StatusText(404), http.StatusNotFound)
		log.Println("Couldn't get page: " + pageGUID)
		log.Println(err.Error())
		return
	} else {
		t, _ := template.ParseFiles("templates/blog.html")
		t.Execute(w, thisPages)
	}
}

func RedirIndex(w http.ResponseWriter, r *http.Request) {
	http.Redirect(w, r, "/home", http.StatusMovedPermanently)
}

func ServeIndex(w http.ResponseWriter, r *http.Request) {
	var Pages = []Page{}
	pages, err := database.Query("SELECT page_title, page_content, page_date, page_guid FROM pages ORDER BY ? DESC", "pages_date")
	if err != nil {
		fmt.Fprintln(w, err.Error())
		log.Println("Couldn't get page. ")
		os.Exit(-2)
	}
	defer pages.Close()
	for pages.Next() {
		thisPage := Page{}
		pages.Scan(&thisPage.Title, &thisPage.RawContent, &thisPage.Date, &thisPage.GUID)
		thisPage.Content = template.HTML(thisPage.RawContent)
		Pages = append(Pages, thisPage)
	}

	t, _ := template.ParseFiles("templates/index.html")
	t.Execute(w, Pages)
}

func (p Page) TruncatedText() string {
	chars := 0
	for i, _ := range p.RawContent {
		chars++
		if chars > 150 {
			return p.RawContent[:i] + `...`
		}
	}
	return p.RawContent
}
