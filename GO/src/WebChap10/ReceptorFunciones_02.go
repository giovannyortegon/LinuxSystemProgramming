package main

import "fmt"

type Contador int

func main() {
	var c Contador

	c.Incremento()
	c.Incremento()
	c.Incremento()

	fmt.Println("valor: ", c)
	c.Reiniciar(7)
	fmt.Println("valor: ", c)
}

func (c *Contador) Incremento() {
	*c++
}

func (c *Contador) Reiniciar(nuevoValor int) {
	*c = Contador(nuevoValor)
}
