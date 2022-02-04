package main

import "fmt"

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

func (p Person) String() string {
	s := p.Name.Personal +  " " + p.Name.Family

	for _, v := range p.Email {
		s += "\n" + v.Kind + ": " + v.Address
	}
	return s
}

func main() {
	person := Person {
		Name: Name { Family: "Newmarch", Personal: "Jan" },
		Email: []Email {
			Email { Kind: "home", Address: "jan@newmarch.name"},
			Email { Kind: "work", Address: "j.newmarch@boxhill.edu"},
		},
	}

	fmt.Println(person.String())
}
