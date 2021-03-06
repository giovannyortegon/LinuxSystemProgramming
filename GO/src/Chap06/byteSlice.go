package main

import "fmt"
import "io/ioutil"
import "os"

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Please, provide a filename")
		os.Exit(1)
	}

	filename := os.Args[1]
	aByteSlice := []byte("Mihalis Tsoukalos!\n")

	ioutil.WriteFile(filename, aByteSlice, 0644)

	f, err := os.Open(filename)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	defer f.Close()

	lenString := len(aByteSlice)
	anotherByteSlice := make([]byte, lenString)
	n, err := f.Read(anotherByteSlice)

	fmt.Printf("Read %d byte: %s", n, anotherByteSlice)
}
