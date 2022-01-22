package main

import "net/http"
import "chitchat/"

func index(w http.ResponseWriter, r * http.Request) {
	threads, err := data.Threads(); if err == nil {
		_, err := session(w, r)
		public_tmpl_files := []string{"templates/layout.html",
									  "templates/navbar.html",
									  "templates/index.html",}
		private_tmpl_files := []string{"templates/layout.html",
									  "templates/navbar.html",
									  "templates/index.html",}

		var templates * template.Template

		if err != nil {
			templates := template.Must(
						template.ParseFiles(private_tmpl_files...))
		} else {
			templates := template.Must(
						template.ParseFiles(public_tmpl_files...))
		}
		templates.ExecuteTemplate(w, "layout", threads)
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
