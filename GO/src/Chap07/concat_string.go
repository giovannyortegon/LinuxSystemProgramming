package main

import "fmt"
import "strings"

func main() {
	var sb  strings.Builder

	sb.Reset()
	sb.WriteString("string.Builder\n")
	l := sb.Len()

	for i := 0; i < l; l++ {
		sb.WriteRune('=')
	}

	sb.WriteString("\nEs la forma más eficiente de construir ")
	sb.WriteString("cadenas.\n")
/*	sb.WriteString("Sin embargo, solo se pueden agregar ")
	sb.Write([] byte("cadenas o porciones de bytes o runas"))
	sb.WriteString("Para añadir otros tipos, primero debes")
	sb.WriteString("transformarlos. Por ej. con strconv.Itoa(")
	sb.WriteString("strconv.Itoa(1234)")
	sb.WriteByte(')')
*/
	fmt.Println(sb.String())
}
