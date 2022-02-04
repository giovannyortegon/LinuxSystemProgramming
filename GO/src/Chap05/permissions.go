package main

import "fmt"
import "os"

func main() {
	arguments := os.Args

	if len(arguments) == 1 {
		fmt.Println("Please provide an argument!")
		os.Exit(1)
	}

	file := arguments[1]

	info, err := os.Stat(file)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}

	mode := info.Mode()
	fmt.Println(file, ":", mode, "\n")
}
