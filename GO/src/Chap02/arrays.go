package main

import "fmt"

func main() {
	myArray := [4]int{1, 2, 4, -4}

	for i := range myArray {
		fmt.Printf("%d ", myArray[i])
	}
}
