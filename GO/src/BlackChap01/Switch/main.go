package main

import "fmt"

func main() {
	var x int;

	x = 2

	if x == 1 {
		fmt.Println("X is equal to 1")
	} else {
		fmt.Println("X is not equal to 1")
	}

	switch x {
		case 1:
			fmt.Println("Found 1")
		case 2:
			fmt.Println("Found 2")
		default:
			fmt.Println("Default case")
	}

	y := "hola"

	switch y {
		case "hola":
			fmt.Println("Found ", y)
		case "bye":
			fmt.Println("Found ", y)
		default:
			fmt.Println("Default")
	}

	nums := []int{2,3,4,5}

	for idx, value := range nums {
		fmt.Println(idx, value)
	}
}
