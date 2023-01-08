package main

import (
	"bufio"
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

		// go echo(conn)
		go echo_cpy(conn)
	}
}

func echo(conn net.Conn) {
	defer conn.Close()

	reader := bufio.NewReader(conn)
	s, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal("Unable to read data.")
	}

	log.Printf("Read %d bytes: %s", len(s), s)

	log.Println("Writing data")
	writer := bufio.NewWriter(conn)
	if _, err := writer.WriteString(s); err != nil {
		log.Fatalln("Unable to write data.")
	}
	writer.Flush()
}

func echo_cpy(conn net.Conn) {
	defer conn.Close()

	if _, err := io.Copy(conn, conn); err != nil {
		log.Fatalln("Unable to read/write data.")
	}
}
