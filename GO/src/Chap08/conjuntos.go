package main

import "fmt"
import "math/rand"

func main() {
	fmt.Println("Los numeros ganadores de la loteria son:")

	numeros := map[int] struct{} {}

	for len(numeros) < 6 {
		n := rand.Intn(49) + 1
		fmt.Println(n)

		// solo se muestra el numero si no ha salido antes
		if valor, ok := numeros[n]; !ok {
			numeros[n] = struct{}{}
			fmt.Println("El", n, "...", valor)
		}
	}

	fmt.Println("Felicidades a los premiados")
}
