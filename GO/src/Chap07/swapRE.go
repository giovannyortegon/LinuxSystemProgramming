package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"os"
	"regexp"
)

func main() {
	flag.Parse()
	if flag.NArg() != 1 {
		fmt.Println("Please provide one log file to process!")
		os.Exit(-1)
	}
	numberOfLine := 0
	numberOfLineMatched := 0

	filename := flag.Arg(0)
	f, err := os.Open(filename)
	if err != nil {
		fmt.Printf("Error opening file %s\n", err)
		os.Exit(1)
	}
	defer f.Close()

	r := bufio.NewReader(f)

	for {
		line, err := r.ReadString('\n')
		if err == io.EOF {
			break
		} else if err != nil {
			fmt.Printf("Error reading file %s", err)
		}

		numberOfLine++
		r := regexp.MustCompile(`(.*) (\[\d\d\/(\w+)/\d\d\d\d:\d\d:\d\d:\d\d(.*)\]) (.*)`)
		if r.MatchString(line) {
			numberOfLineMatched++
			match := r.FindStringSubmatch(line)
			fmt.Println(match[1], match[6], match[5], match[2])
		}
	}

	fmt.Println("Line processed: ", numberOfLine)
	fmt.Println("Line matched: ", numberOfLineMatched)
}
