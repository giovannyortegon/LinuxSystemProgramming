package main

import "fmt"

func unnameMinMax(x int, y int) (int, int){
	if x > y {
		min := y
		max := x
		return min, max
	} else {
		min := x
		max := y
		return min, max
	}
}

func minMax(x int, y int) (min int, max int) {
	if x > y {
		min = y
		max = x
	} else {
		min = x
		max = y
	}
	return min, max
}

func namedMinMax(x int, y int) (min int, max int) {
	if x > y {
		min = y
		max = x
	} else {
		min = x
		max = y
	}
	return
}

func sort(x int, y int) (int, int) {
	if x > y {
		return x, y
	} else {
		return y, x
	}
}

func main() {
	y := 4
	square := func(s int) int {
		return s * s
	}

	fmt.Println("The square of", y, "is", square(y))

	square = func(s int) int {
		return s + s
	}

	fmt.Println("The square of", y, "is", square(y))

	fmt.Println(minMax(15, 6))
	fmt.Println(namedMinMax(15, 6))
	min, max := namedMinMax(12, -1)
	fmt.Println(min, max)
}
