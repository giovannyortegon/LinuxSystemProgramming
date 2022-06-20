package main

import "fmt"

func main() {
	// creando un mapa con clave:string, valor entero
	//pasaporte := map[string] int{}

	capitales := map[string] string {
		"España": "Madrid",
		"Francia": "Paris",
		"Reino Unido": "Londres",
		"Japon": "Tokio",
	}

	capitales["Italia"] = "Roma"
	pais := "Francia"
	capital := capitales[pais]

	fmt.Printf("La capital de %s es %s\n\n", pais, capital)

	pais = "Narnia"

	capital, ok := capitales[pais]

	if ok {
		fmt.Println("La capital de", pais, "es", capital)
	} else {
		fmt.Println("No encontrado capital para", pais)
	}
	fmt.Println()

	numero := len(capitales)
	fmt.Println("Numero de capitales:", numero)
	for pais, capital := range capitales {
		fmt.Printf("La capital de %s es %s\n", pais, capital)
	}

	fmt.Println()
	fmt.Println("Borrando Reino Unido:")
	delete(capitales, "Reino Unido")
	fmt.Println()

	numero = len(capitales)
	fmt.Println("Numero de capitales:", numero)

	for pais, capital := range capitales {
		fmt.Printf("La capital de %s es %s\n", pais, capital)
	}
}
