/*
 * JSONEchoServer
 */
package main

import (
	"encoding/json"
	"fmt"
	"net"
	"os"
)

type Person struct {
	Name  Name
	Email []Email
}

type Name struct {
	Family string
	Person string
}

type Email struct {
	Kind    string
	Address string
}

func (p Person) String() string {
	s := p.Name.Person + " " + p.Name.Family

	for _, v := range p.Email {
		s += "\n" + v.Kind + ": " + v.Address
	}

	return s
}

func main() {
	service := ":1200"
	tcpAddr, err := net.ResolveTCPAddr("tcp", service)
	checkError(err)

	listener, err := net.ListenTCP("tcp", tcpAddr)
	checkError(err)

	for {
		conn, err := listener.Accept()
		if err != nil {
			continue
		}

		encoder := json.NewEncoder(conn)
		decoder := json.NewDecoder(conn)

		for n := 0; n < 10; n++ {
			var person Person
			decoder.Decode(&person)

			fmt.Println(person.String())
			encoder.Encode(person)
		}
		conn.Close()
	}
}

func checkError(err error) {
	if err != nil {
		fmt.Println("Fatal Error ", err.Error())
		os.Exit(1)
	}
}
