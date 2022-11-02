package main

import "fmt"

type Person struct {
	name string
	age  int
}

type Employee struct {
	id int
}

type FullTimeEmployee struct {
	Person
	Employee
}

func (ftEmp FullTimeEmployee) getMessage() string {
	return "FullTime Employee"
}

type TemporaryEmployee struct {
	Person
	Employee
	taxRate int
}

func (TEmp TemporaryEmployee) getMessage() string {
	return "Temporary Employee"
}

type PrintInfo interface {
	getMessage() string
}

func getMessage(p PrintInfo) {
	fmt.Println(p.getMessage())
}

func main() {
	FtEmp := FullTimeEmployee{}

	FtEmp.id = 0
	FtEmp.name = "Juan"
	FtEmp.age = 25
	fmt.Printf("%v\n", FtEmp)
	getMessage(FtEmp)

	TEmp := TemporaryEmployee{}
	getMessage(TEmp)
	fmt.Printf("%v\n", FtEmp)

}
