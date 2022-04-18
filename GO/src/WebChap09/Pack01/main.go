package main

import (
	"fmt"
	"github.com/mariomac/analizador"
	"modules/ejemplo"
)

func main() {
	fmt.Println("Como te llamas: ")
	var nombre string

	fmt.Scanln(&nombre)
	fmt.Println(hola.ConNombre(nombre))

	analizador.PrintEstadistica(nombre)
}
