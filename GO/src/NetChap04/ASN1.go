/*
 * ASN1
 */
package main

import "encoding/asn1"
import "fmt"
import "os"

func main() {
	val := 13
	fmt.Println("Before marshal/unmarshal: ", val)
	mdata, err := asn1.Marshal(val)
	checkError(err)

	var n int

	fmt.Println("Data:", mdata)
	_, err1 := asn1.Unmarshal(mdata, &n)
	checkError(err1)

	fmt.Println("After marshal/unmarshal: ", n)

	os.Exit(0)
}

func checkError(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
		os. Exit(1)
	}
}
