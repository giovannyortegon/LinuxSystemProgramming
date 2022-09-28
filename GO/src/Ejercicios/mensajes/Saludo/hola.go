package hola

import "fmt"

func Saludo(nombre string) string {
	return fmt.Sprintf("Hola %s, Como estas?\n", nombre)
}
