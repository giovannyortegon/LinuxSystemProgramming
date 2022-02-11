package main

import "fmt"

func withPointer(x * int) {
	* x = * x * * x
}

type complex struct {
	x int
	y int
}

func newComplex(x int, y int) * complex {
	return &complex {x, y}
}

func main() {
	x := -2
	withPointer(&x)
	fmt.Println(x)

	w := newComplex(4, 5)
	fmt.Println(*w)
	fmt.Printf("%p",w)
}
