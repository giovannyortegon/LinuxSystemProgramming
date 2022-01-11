package main

import "fmt"
import "strconv"

func PassMap(aMap map[string] int, key string, value int) map[string] int {
	aMap[key] = value
	return aMap
}

func AnotherMap(aMap map[string] int, key string, value int) {
	aMap[key] = value
}

func main() {
	anArray := [4]int {1, -2, 14, 0}
	aMap := make(map[string] int)

	length := len(anArray)

	for i := 0; i < length; i++ {
		fmt.Printf("%s ", strconv.Itoa(i))
//		aMap[strconv.Itoa(i)] = anArray[i]
//		aMap = PassMap(aMap, strconv.Itoa(i), anArray[i])
//		PassMap(aMap, strconv.Itoa(i), anArray[i])
		AnotherMap(aMap, strconv.Itoa(i), anArray[i])
	}
	fmt.Println()
	for key, value := range aMap {
		fmt.Printf("%s: %d ", key, value)
	}

	fmt.Println()
}
