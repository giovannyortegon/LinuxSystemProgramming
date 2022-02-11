package main

import "fmt"
import "runtime"

func main() {
	fmt.Print("You are using ", runtime.Compiler, " ")
	fmt.Println("on a", runtime.GOARCH, "machinea")
	fmt.Println("with GO version", runtime.Version())
	fmt.Println("Number of Goroutine:", runtime.NumGoroutine())
}
