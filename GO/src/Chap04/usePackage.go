package main

import "aSimplePackage"
import "fmt"

func main() {
	temp := aSimplePackage.Add(5, 10)
	fmt.Println(temp)

	fmt.Println(aSimplePackage.Pi)
}
