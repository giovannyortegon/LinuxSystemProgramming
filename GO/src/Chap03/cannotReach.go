package main

import "fmt"

func x() int {
	return -1
	fmt.Println("Exiting x()")
	return -1
}

func y() int {
	return -1
	fmt.Println("Exiting y()")
	return -1
}

func main(){
	fmt.Println(x())
	fmt.Println("Exiting program...")
}
