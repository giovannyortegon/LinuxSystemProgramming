package main

import "fmt"
import "sort"

func main() {
	var num int
	array := make([] int, 1)
	for ;; {
		fmt.Println("Insert Number: ")
		fmt.Scanln(&num)
		if num == 0 {
			break
		} else if array[0] == 0 {
			array[0] = num
		} else {
			array = append(array, num)
		}
	}
	sort.Ints(array)
	fmt.Println(array)
	fmt.Println("Numero menor:",array[0])
	fmt.Println("Numero mayor:",array[len(array) -1])
}
