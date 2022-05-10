package main

import (
	"fmt"
)

type Cuboide struct {
	Ancho float64
	Alto float64
	Profundo float64
}

func main() {
	c := Cuboide{Ancho: 2, Profundo:3, Alto: 2}
	fmt.Printf("Cuboide: %v. Volumen: %v")
}

func (c Cuboide) String() string {
	return fmt.Sprintf("%v %v %v", c.Alto, c.Ancho, c.Profundo)
}

func (c Cuboide) Volumen() float64 {
	return c.Ancho * c.Alto * c.Profundo
}

func (c * Cuboide) Redimensionar(an, al, pro float64) {
	c.Ancho = an
	c.Alto = al
	c.Profundo = pro
}