package main

import ("fmt")

func main() {
	fmt.Println("Lanzando gorrutina")

	go cincoVeces("Esta gorrutina no siempre se completara")
	
	cincoVeces("Este mensaje se mostrara exactamente 5 veces.")

	fmt.Println("Finalizando programa")
}

func cincoVeces(msg string) {
	for i := 1; i <= 5; i++ {
		fmt.Printf("(%d de 5) %s\n", i, msg)
	}
}