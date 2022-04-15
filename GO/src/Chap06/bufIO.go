package main

import "fmt"
import "bufio"
import "os"

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Please, provide a filename")
		os.Exit(1)
	}

	filename := os.Args[1]

	f, err := os.Open(filename)
	if err != nil {
		fmt.Printf("error opening %s: %s", filename, err)
		os.Exit(1)
	}

	defer f.Close()

	scanner := bufio.NewScanner(f)

	for scanner.Scan() {
		line := scanner.Text()

		if scanner.Err() != nil {
			fmt.Println("error reading file: %s", err)
		}
		fmt.Println(line)
	}
}
