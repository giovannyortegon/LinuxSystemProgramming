package main

import "fmt"

type Saludador interface {
	Saluda() string
	Saltar() string
}
type Perro struct{}
type Gato struct{}

func main() {
	var sld Saludador
	sld = Perro{}
	fmt.Println("El perro saluda ", sld.Saluda())
	fmt.Println("y salta ", sld.Saltar())
	sld = Gato{}
	fmt.Println("El gato saluda ", sld.Saluda())
	fmt.Println("y salta ", sld.Saltar())
}

func (p Perro) Saluda() string {
	return "Guau!!"
}

func (g Gato) Saluda() string {
	return "Miau!!"
}

func (p Perro) Saltar() string {
	return "medio"
}

func (g Gato) Saltar() string {
	return "alto"
}
