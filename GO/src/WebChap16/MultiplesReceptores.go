package main

import (
	"fmt"
	"time"
)

func main() {

	dulces := make(chan string, 10)

	go Engullidor("Marcos", dulces)
	go Engullidor("Aina", dulces)
	go Engullidor("Judith", dulces)

	dulces <- "Donut"

	time.Sleep(time.Second)
	dulces <- "Cruasan"
	time.Sleep(time.Second)
	dulces <- "Ensaimada"
	time.Sleep(time.Second)

}

func Engullidor(nombre string, dulces <-chan string) {
	for dulce := range dulces {
		fmt.Println(nombre, "come", dulce)
	}
}
