package main

import (
	"fmt"
	"net"
)

func main() {
	for i := 0; i < 1024; i++ {
		address := fmt.Sprintf("scanme.nmap.org:%d", i)
		// fmt.Println(address)
		conn, err := net.Dial("tcp", address)
		if err != nil {
			// fmt.Printf("Port: %d closed.", i)
			continue
		} else {
			fmt.Print("[-] Connection Successful on ")
			fmt.Printf("%d open\n", i)
		}

		conn.Close()
	}
}
