/*
 * SaveGob
 */
package main

import (
	"encoding/gob"
	"fmt"
	"os"
)

type Person struct {
	Name Name
	Email [] Email
}

type Name struct {
	Family string
	Personal string
}

type Email struct {
	Kind string
	Address string
}

func main() {
	person := Person{
		Name: Name{Family: "Newmarch", Personal: "Jan"},
		Email: []Email{
			Email{Kind: "home", Address: "jan@newmarch.name"},
			Email{Kind: "work", Address: "j.nrewmarch@boxhill.au"}},
	}

	saveGob("person.gob", person)
}

func saveGob(filename string, key interface{}) {
	outFile, err := os.Create(filename)
	checkError(err)
	encoder := gob.NewEncoder(outFile)
	err = encoder.Encode(key)
	checkError(err)
	outFile.Close()
}

func checkError(err error) {
	if err != nil {
		fmt.Println("Fatal error ", err.Error())
		os.Exit(1)
	}
}