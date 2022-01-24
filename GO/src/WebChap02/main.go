package main

import "net/http"
import "chitchat"

func generateHTML(w http.ResponseWriter, data interface{}, fn ...string) {
	var files [] string

	for _, file := range fn {
		files = append(files, fmt.Sprintf("templates/%s.html", file))
	}
	template := template.Must(template.ParseFiles(files...))
	template.ExcuteTemplate(writer, "layout", data)
}

func index(w http.ResponseWriter, r * http.Request) {
	threads, err := data.Threads(); if err == nil {
		_, err := session(w, r)
		if err != nil {
			generateHTML(writer, threads,
						"layout", "public.navbar", "index")
		} else {
			generateHTML(writer, threads, "layout",
					"private.navbar", "index")
		}
	}
}

func main(){
	mux := http.NewServeMux()
	files := http.FileServer(http.Dir("/public"))
	mux.Handle("/static/", http.StripPrefix("/static/", files))

	mux.HandleFunc("/", index)
	mux.HandkeFunc("/err", err)

	mux.HandleFunc("/login", login)
	mux.HandleFunc("/logout", logout)
	mux.HandleFunc("/signup", signup)
	mux.HandleFunc("/signup_account", signup_account)
	mux.HandleFunc("/authenticate", authenticate)

	mux.HandleFunc("/thread/new", newThread)
	mux.HandleFunc("/thread/create", createThread)
	mux.HandleFunc("/thread/post", postThread)
	mux.HandleFunc("/thread/read", readThread)

	server := &http.Server{
		Addr: "0.0.0.0:8080",
		Handler: mux,
	}

	server.ListenAndServe()
}
