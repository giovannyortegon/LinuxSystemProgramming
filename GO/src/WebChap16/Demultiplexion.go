package main

import (
	"fmt"
	"time"
)

func main() {
	sms := make(chan string, 5)
	email := make(chan string, 5)
	carta := make(chan string, 5)

	go CentralMensajera(sms, email, carta)

	sms <- "332132434"
	email <- "yafdsfd@yahoo.com"
	carta <- "Banco central hispano"
	email <- "fasdfsadf@hotmail.com"

	time.Sleep(time.Second)
}

func CentralMensajera(sms, email, carta <-chan string) {

	for {
		select {
		case num := <-sms:
			fmt.Println("recibido SMS del numero", num)
		case dir := <-email:
			fmt.Println("recibido email de direccion", dir)
		case rem := <-carta:
			fmt.Println("recibida cara de remitente", rem)
		}
	}
}
