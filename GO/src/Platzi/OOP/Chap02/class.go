package main

import "fmt"

type Employee struct {
	id   int
	name string
}

func (e *Employee) SetId(id int) {
	e.id = id
}

func (e *Employee) GetId() int {
	return e.id
}

func (e *Employee) SetName(name string) {
	e.name = name
}

func (e *Employee) GetName() string {
	return e.name
}

// constructor
func NewEmployee(id int, name string) *Employee {
	return &Employee{
		id:   id,
		name: name,
	}
}

func main() {
	e := Employee{}

	fmt.Printf("%v\n", e)
	e.id = 1
	e.name = "Juan"

	fmt.Printf("%v\n", e)
	e.SetId(5)
	fmt.Printf("%v\n", e)
	e.name = "Amanda"
	fmt.Printf("%v\n", e)

	fmt.Println(e.GetId())
	fmt.Println(e.GetName())

	e1 := Employee{
		id:   2,
		name: "Manuel",
	}
	fmt.Printf("%v", e1)

	e2 := NewEmployee(3, "Rosa")
	fmt.Printf("\n%v", *e2)

	e4 := new(Employee)
	e4.id = 4
	e4.name = "Felipe"
	fmt.Printf("\n%v\n", *e4)
}
