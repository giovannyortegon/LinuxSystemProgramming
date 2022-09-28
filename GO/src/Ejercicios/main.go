package main

import "fmt"
import "moduls/mensajes/Saludo"
import "moduls/mensajes/Despedida"
import "moduls/mensajes/Mensaje"

func main() {
	var nombre string

	fmt.Print("Ingrese nombre: ")
	fmt.Scanln(&nombre)

	fmt.Println(hola.Saludo(nombre))
	mensaje.Mensaje()
	despedida.Adios(nombre)
}
