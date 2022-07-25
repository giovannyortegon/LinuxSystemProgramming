package main

import (
	"context"
	"fmt"
	"time"
)

func main() {
	ctx, cancela := context.WithCancel(context.Background())

	fmt.Println("Un mensaje se mostrara en 5 segundos...")

	go func() {
		fmt.Println("Pulsa INTRO para cancelar mensaje")
		fmt.Scanf("\n")
		cancela()
	}()

	MuestraRetardada(ctx, "Hola")
	fmt.Println("Finalizando")

}

func MuestraRetardada(ctx context.Context, msg string) {
	select {
	case <-time.After(5 * time.Second):
		fmt.Println(msg)
	case <-ctx.Done():
		println("Proceso interrumpido la funcion continua")
	}
}
