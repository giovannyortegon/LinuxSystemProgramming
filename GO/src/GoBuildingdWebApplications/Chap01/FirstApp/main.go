package main

import (
	"fmt"
	"net/http"
	"time"
)

const (
	Port = ":8080"
)

func main() {
	http.HandleFunc("/static", serveStatic)
	http.HandleFunc("/", serveDynamic)
	http.ListenAndServe(Port, nil)
}

func serveDynamic(w http.ResponseWriter, r *http.Request) {
	response := "The time is now " + time.Now().String()
	fmt.Fprintln(w, response)
}

func serveStatic(w http.ResponseWriter, r *http.Request) {
	http.ServeFile(w, r, "static.html")
}
