package main

import (
	"io"
	"log"
	"net"
)

func main() {
	
	listener, err := net.Listen("tcp", ":20080")
	if err != nil {
		log.Fatalln("Unable to bind to port.")
	}
	log.Println("Listening on 0.0.0.0.:20080")

	for {
		conn, err := listener.Accept()
		log.Printf("Received connection")
		if err != nil {
			log.Fatalln("Unable to accept connection.")
		}

		go echo(conn)
	}
}

func echo(conn net.Conn) {
	defer conn.Close()

	// Create a buffer to store received data.
	b := make([]byte, 512)

	for {
		// Receive data via conn.Read into a buffer
		size, err := conn.Read(b[0:])
		if err == io.EOF {
			log.Println("Client disconnected.")
			break
		}

		if err != nil {
			log.Println("Unexpected error.")
			break
		}

		log.Printf("Received %d bytes: %s\n", size, string(b))

		// send data via conn.Write.
		log.Println("Writing data")
		if _, err := conn.Write(b[0:size]); err != nil {
			log.Fatalln("Unable to write data.")
		}
	}
}
