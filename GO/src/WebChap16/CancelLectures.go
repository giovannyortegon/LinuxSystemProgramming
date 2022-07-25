package main

import (
	"fmt"
	"time"
)

func main() {

	ch := make(chan int)

	go func() {

		fmt.Println("Calculando la respuesta a la gran pregunta" +
			" de la vida, el universo, y Todo lo demas")
		time.Sleep(15 * time.Second)
		ch <- 42
	}()

	fmt.Println("Esperando...")

	select {
	case ret := <-ch:
		fmt.Println("Recibido: ", ret)
	case <-time.After(2 * time.Second):
		fmt.Println("Error: tiempo de espera agotado")
	}
}
