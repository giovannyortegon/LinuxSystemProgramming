package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
	"time"
)

var TOTALWRITE int = 0
var ENTRIESPERLOGFILE int = 100
var WHENTOSTOP int = 230
var openLogFile os.File

func main() {
	numberOfLogEntries := 0
	filename := "/tmp/myLog.log"
	err := setUpLogFile(filename)
	if err != nil {
		fmt.Print(err)
		os.Exit(-1)
	}

	for {
		log.Println(numberOfLogEntries, "This is a test log entry")
		numberOfLogEntries++
		TOTALWRITE++

		if numberOfLogEntries > ENTRIESPERLOGFILE {
			rotateLogFile(filename)
			numberOfLogEntries = 0
		}

		if TOTALWRITE > WHENTOSTOP {
			rotateLogFile(filename)
			break
		}

		time.Sleep(time.Second)
	}

	fmt.Println("Wrote", TOTALWRITE, "Log entries!")
}

func rotateLogFile(filename string) error {
	defer openLogFile.Close()
	os.Rename(filename, filename+"."+strconv.Itoa(TOTALWRITE))

	err := setUpLogFile(filename)

	return err
}

func setUpLogFile(filename string) error {
	openLogFile, err := os.OpenFile(filename, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0644)
	if err != nil {
		return err
	}

	log.SetOutput(openLogFile)

	return nil
}
