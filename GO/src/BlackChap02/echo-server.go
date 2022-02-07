package main

import "log"
import "net"
import "io"

func main() {
	// Bind to TCP port 20080 on all interfaces.
	listener, err := net.Listen("tcp", ":20080")
	if err != nil {
		log.Fatalln("Unable to bind to port")
	}

	log.Println("Listening on 0.0.0.0:20080")
	for {
		// wait for connection.
		// Create net.Conn on connection established
		conn, err := listener.Accept()
		log. Println("Received connection")
		if err != nil {
			log.Fatalln("Unable to accept connection")
		}
		// handle the connection. Using go routine for concurrency
		go echo(conn)
	}
}

func echo (conn net.Conn) {
	defer conn.Close()

	// Create a buffer to store received data.
	b := make([]byte, 512)

	for {
		// Receive data via conn.Read into a buffer.
		size, err := conn.Read(b[0:])
		if err == io.EOF {
			log.Println("Client disconnected")
			break
		}

		if err != nil {
			log.Println("Unexpected error")
			break
		}

		log.Printf("Received %d bytes: %s\n", size, string(b))

		// send data via conn.Write
		log.Println("Write data")
		if _, err := conn.Write(b[0:size]); err != nil {
			log.Fatalln("Unable to write data")
		}
	}
}
