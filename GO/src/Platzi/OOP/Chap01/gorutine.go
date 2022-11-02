package main

import (
	"fmt"
	"time"
)

func main() {
	c := make(chan int)
	go doSomething(c)

	fmt.Println(<-c)
}

func doSomething(c chan int) {
	time.Sleep(3 * time.Second)

	fmt.Println("Done")

	c <- 1
}
