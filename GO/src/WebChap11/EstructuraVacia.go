package main

import "fmt"

func main() {
	duplicados := [] string {
		"Juan", "Maria", "Benito", "Juan", "Carlos", "Mario",
		"Benito", "Carlos", "Maria", "Juan", "Cristina",
		"Isabel", "Carlos", "Juan", "Belinda",
	}

	unicos := map[string] struct {} {}

	for _, nombre := range duplicados {
		unicos[nombre] = struct {} {}
	}

	fmt.Println("La lista de nombres unicos son: ")
	for nombre := range unicos {
		fmt.Println("-", nombre)
	}
}