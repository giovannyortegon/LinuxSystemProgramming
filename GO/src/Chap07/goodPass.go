package main

import (
	"fmt"
	"math/rand"
	"os"
	"path/filepath"
	"strconv"
	"encoding/binary"
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
	f, _ := os.Open("/dev/random")
	var seed int64
	binary.Read(f, binary.LittleEndian, &seed)
	rand.Seed(seed)
	f.Close()
	fmt.Println("Seed: ", seed)

	startChar := "!"
	var i int64

	for i = 0; i < LENGTH; i++ {
		anInt := int(random(MIN, MAX))
		newChar := string(startChar[0] + byte(anInt))
		if newChar == " " {
			i = i - i
			continue
		}
		fmt.Print(newChar)
	}
	fmt.Println()
}

func random(min int, max int) int {
	return rand.Intn(max-min) + min
}
