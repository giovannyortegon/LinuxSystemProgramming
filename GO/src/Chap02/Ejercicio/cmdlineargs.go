package main

import "fmt"
import "os"


func main() {
	args := os.Args
	LenArgs := len(args)

	for i := 0; i < LenArgs; i++ {
		if args[i] == "-i" {
			fmt.Println(args[i])
		}
		if args[i] == "-k" {
			fmt.Println(args[i])
		}
	}
}
