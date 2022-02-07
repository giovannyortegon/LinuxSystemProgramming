package main

import "fmt"

type Person struct {
	Name string
	Age int
}

func (p * Person) SayHello() {
	fmt.Print("Hello ", p.Name, ", you are ", p.Age, " old")
}

func main() {
	var guy = new (Person)
	guy.Name = "Dave"
	guy.Age = int(36)
	guy.SayHello()
}
