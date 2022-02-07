package main

import "fmt"

func main() {
	var m = make(map[string] string)
	m["a"] = "hola"
	fmt.Println("m: ", m["a"])

	// map literal
	m1 := map[string]int {
		"k1": 12,
		"k2": 13,
		"k3": 14,
	}
	fmt.Println("k2: ", m1["k2"])

	fmt.Println("Print map literal")

	for key, value := range m1 {
		fmt.Println(key, value)
	}
	fmt.Println("Deleting k1")
	delete(m1, "k1")

	for key, value := range m1 {
		fmt.Println(key, value)
	}

	fmt.Println("Add new key and value")
	m1["k5"] = 15
	m1["k1"] = 12

	for key, value := range m1 {
		fmt.Println(key, value)
	}
}
