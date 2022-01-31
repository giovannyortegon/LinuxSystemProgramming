package main

import "flag"
import "fmt"

func main() {
	miniusO := flag.Bool("o", false, "o")
	miniusC := flag.Bool("c", false, "c")
	miniusK := flag.Int("k", 0, "an int")

	flag.Parse()

	fmt.Println("-o:", *miniusO)
	fmt.Println("-c:", *miniusC)
	fmt.Println("-k:", *miniusK)

	for index, val := range flag.Args() {
		fmt.Println(index, ":", val)
	}
}
