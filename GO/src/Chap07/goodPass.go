package main

import (
	"fmt"
	"math/rand"
	"os"
	"path/filepath"
	"strconv"
)

var MAX int = 10
var MIN int = 0
var seedSize int = 10

func main() {
	if len(os.Args) != 2 {
		fmt.Printf("Usage: %s length\n", filepath.Base(os.Args[0]))
		os.Exit(1)
	}

	LENGTH, _ := strconv.ParseInt(os.Args[1], 10, 64)
	f, _ := os.Open()
}

func random(min int, max int) int {
	return rand.Intn(max-min) + min
}
