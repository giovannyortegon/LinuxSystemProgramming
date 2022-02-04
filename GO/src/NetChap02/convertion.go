package main

import "fmt"

func main() {
	var b[] byte
	var s string

	b = []byte("string")
	fmt.Println(b)

	s = string(b[:])
	fmt.Println(s)
}
