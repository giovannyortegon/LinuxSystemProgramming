package main

import "fmt"

type Person struct {
	Name string
	Age int
}

func (p * Person) SayHello() {
	fmt.Println("Hello ", p.Name, ", You are ", p.Age)
}

type Friend interface {
	SayHello()
}

func Greet (f Friend) {
	f.SayHello()
}

type Dog struct {}

func (d * Dog) SayHello() {
	fmt.Println("Woof woof")
}

func main() {
	var guy = new(Person)
	guy.Name = "Dave"
	guy.Age = 37
	Greet(guy)
	var dog = new(Dog)
	Greet(dog)
}
