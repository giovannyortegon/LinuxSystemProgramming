package main

import "fmt"
import "flag"
import "os"
import "strings"

func main() {
	minusA := flag.Bool("a", false, "a")
	minusS := flag.Bool("s", false, "s")

	flag.Parse()
	flags := flag.Args()
	if len(flags) == 0 {
		fmt.Println("Please provide an argument!")
		os.Exit(1)
	}

	file := flags[0]
	fountIt := false

	path := os.Getenv("PATH")
//	fmt.Println(path)
	pathSlice := strings.Split(path, ":")
//	fmt.Println(pathSlice)
	for _, directory := range pathSlice {
		fullPath := directory + "/" + file
		fileInfo, err := os.Stat(fullPath)
		if err == nil {
			mode := fileInfo.Mode()
//			fmt.Println(mode)
			if mode.IsRegular() {
				if mode & 00111 != 0 {
					fountIt = true
					if * minusS == true {
						os.Exit(0)
					}
					if * minusA == true {
						fmt.Println(fullPath)
						os.Exit(0)
					} else {
						fmt.Println(fullPath)
						os.Exit(0)
					}
				}
			}
		}
	}

	if fountIt == false {
		os.Exit(1)
	}
}
