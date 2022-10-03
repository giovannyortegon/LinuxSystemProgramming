package main

import (
	"net/http"
	"os"

	"github.com/gorilla/mux"
)

const (
	PORT = ":8080"
)

func main() {
	rtr := mux.NewRouter()
	rtr.HandleFunc("/pages/{id:[0-9]}", pageHandler)
	// rtr.HandleFunc("/homepages", pageHandler)
	// rtr.HandleFunc("/contact", pageHandler)
	http.Handle("/", rtr)
	http.ListenAndServe(PORT, nil)
}

func pageHandler(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	pageID := vars["id"]
	fileName := "files/" + pageID + ".html"

	_, err := os.Stat(fileName)
	if err != nil {
		fileName = "files/404.html"
	}

	http.ServeFile(w, r, fileName)
}
