package main

import "fmt"
import "os"
import "strconv"

func main() {
	arguments := os.Args

	sum := 0

	LenArgs := len(arguments)

	if LenArgs == 1 || LenArgs > 3 || LenArgs == 2 {
		fmt.Println("[X] Usage: ./program <arg1> <arg2>")
		return
	}

	for i := 1; i < len(arguments); i++ {
		temp, err  := strconv.Atoi(arguments[i])
		if err != nil {
			fmt.Printf("[!] %s is not a number.", arguments[i])
			return
		}
		sum = sum + temp
	}

	fmt.Println("Sum: ", sum)
}
