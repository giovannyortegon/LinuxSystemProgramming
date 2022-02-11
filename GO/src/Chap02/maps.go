package main

import "fmt"

func main() {
	aMap := make(map[string] int)

	aMap["Mon"] = 0
	aMap["Tue"] = 1
	aMap["Wed"] = 2
	aMap["Thu"] = 3
	aMap["Fri"] = 4
	aMap["Sat"] = 5
	aMap["Sun"] = 6

	fmt.Printf("Sunday is the %d th day of the  week.\n", aMap["sun"])

	_, ok := aMap["Tuesday"]
	if ok {
		fmt.Printf("The Tuesday key exists!\n")
	} else {
		fmt.Printf("The Tuesday key does not exist!\n")
	}

	count := 0

	delete(aMap, "Fri")

	for _, _ = range aMap {
		count++
	}

	fmt.Printf("The aMap has now %d elements\n", count)

	anotherMap := map[string] int {
		"One": 1,
		"Two": 2,
		"Three": 3,
		"Four": 4,
	}

	anotherMap["Five"] = 5
	count = 0

	for key, value := range anotherMap {
		fmt.Printf("%s: %d\n", key, value)
		count++
	}

	fmt.Printf("anotherMap has %d elements\n", count)
}
