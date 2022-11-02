package main

import (
	"database/sql"
	"fmt"
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
	Title   string
	Content string
	Date    string
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
	http.Handle("/", routes)
	http.ListenAndServe(PORT, nil)

}

func ServerPage(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	pageGUID := vars["guid"]
	thisPages := Page{}

	fmt.Println(pageGUID)

	err := database.QueryRow("SELECT page_title, page_content, page_date FROM pages WHERE page_guid=?",
		pageGUID).Scan(&thisPages.Title, &thisPages.Content, &thisPages.Date)
	if err != nil {
		http.Error(w, http.StatusText(404), http.StatusNotFound)
		log.Println("Couldn't get page: " + pageGUID)
		log.Println(err.Error())
	} else {
		html := `<html><head><title>` + thisPages.Title + `</title></head>` +
			`<body><h1>` + thisPages.Title + `</h1></div>` + thisPages.Content +
			`</div></body></html>`

		fmt.Fprintln(w, html)
	}
}
