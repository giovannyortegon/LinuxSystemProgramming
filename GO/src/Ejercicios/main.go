package main

import "fmt"
import "moduls/mensajes/Saludo"
import "moduls/mensajes/Despedida"


func main() {
	var nombre string

	fmt.Print("Ingrese nombre: ")
	fmt.Scanln(&nombre)

	fmt.Println(hola.Saludo(nombre))
	despedida.Adios(nombre)
}
