package main

import "fmt"
import "log"
import "os"

// FoorReader defines an io.Reader to read from stdin
type FooReader struct {}
// FooWriter difines an io.Writer to write to  Stdout
type FooWriter struct {}

func main() {
	// Instantiate reader and writer
	var reader FooReader
	var writer FooWriter

	// Create buffer to hold input/output
	input := make([]byte, 4096)

	// Use reader to read input
	s, err := reader.Read(input)
	if err != nil {
		log.Fatalln("Unable to read data")
	}

	fmt.Printf("Read %d bytes from stdin\n", s)

	// Use writer to write output
	s, err = writer.Write(input)
	if err != nil {
		log.Fatalln("Unable to write")
	}

	fmt.Printf("Wrote %d bytes to stdout\n", s)
}

// Reader reads data from stdin
func (fooReader * FooReader) Read (b []byte) (int, error) {
	fmt.Print("in > ")
	return os.Stdin.Read(b)
}

// Write writes data to Stdout
func (fooWriter * FooWriter) Write (b []byte) (int, error) {
	fmt.Print("out > ")
	return os.Stdout.Write(b)
}
