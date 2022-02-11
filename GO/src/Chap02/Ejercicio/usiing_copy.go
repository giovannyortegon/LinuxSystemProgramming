package main

import "fmt"

func main() {
	s1 := [] int {1,3, 43, 6}
	s2 := []int {3,5,1}
	s3 := make([] int, 8)

	fmt.Println(s1)
	fmt.Println(s2)
	fmt.Println(s3)

	fmt.Println("******************")
	copy(s1, s3)
	copy(s3, s2)

	fmt.Println("Copy s3 in s1")
	fmt.Println(s1)
	fmt.Println("Copy s2 in s3")
	fmt.Println(s3)
}
