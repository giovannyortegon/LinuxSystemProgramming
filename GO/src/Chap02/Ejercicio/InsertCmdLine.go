package main

import "fmt"
import "sort"
import "os"
import "strconv"


func main() {
	args := os.Args
	var array [] int

//	fmt.Println(args)
//	fmt.Println(len(args))
	LenArr := len(args)

	for i := 1; i < LenArr; i++ {
		num, _ := strconv.Atoi(args[i])
		array = append(array, num)
	}
	sort.Ints(array)
	fmt.Println(array)
	fmt.Println("EL numero menor:", array[0])
	fmt.Println("EL numero mayor:", array[LenArr-2])
}
