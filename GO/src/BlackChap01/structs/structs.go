package main

import "fmt"

type aStructure struct {
	person string
	height int
	weight int
}

func main() {

	mySlice := make([]aStructure, 0)

	mySlice = append(mySlice, aStructure{"Mihalis", 180, 90})
	mySlice = append(mySlice, aStructure{"Bill", 134, 45})
	mySlice = append(mySlice, aStructure{"Marietta", 155, 45})

	fmt.Println("0:", mySlice)

	integers := make([]int, 2)

	integers = nil
	integers = append(integers, 10)
	integers = append(integers, 20)
	fmt.Println(integers)

	for _, idx := range integers {
		fmt.Println(idx)
		if idx == nil {
			fmt.Println("nil found")
		}
	}
}
