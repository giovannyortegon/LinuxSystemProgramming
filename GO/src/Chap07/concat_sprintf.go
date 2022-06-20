package main

import "fmt"

func main() {
	val := 1.3

	str := fmt.Sprintf("val: %.2f\n", val)

	fmt.Println(str)
}
