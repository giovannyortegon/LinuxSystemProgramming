package main

import "fmt"
import "sync"

func main() {
	const numTareas = 3

	wg := sync.WaitGroup{}
	wg.Add(numTareas)

	for i := 0; i < numTareas; i++ {
		numTarea := i
		go func() {
			defer wg.Done()
			fmt.Println("Ejecutando tarea", numTarea)
		}()
	}

	wg.Wait()

	fmt.Println("Completadas todas las tareas. Finalizando")
}