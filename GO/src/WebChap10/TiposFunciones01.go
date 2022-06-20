package main

import (
	"fmt"
	"math/rand"
)

type Generador func() int

func main() {
	cnt := Contador()

	fmt.Println(cnt())
	fmt.Println(cnt())
	fmt.Println(cnt())

	cnt = Contador()

	fmt.Println(cnt())
	rnd := Aleatorio(456)

	for i := 0; i < 5; i++ {
		fmt.Println(GeneradorTodo(Cero, cnt, rnd))
	}

}

func Cero() int {
	return 0
}

func Contador() Generador {
	cuenta := 0

	return func() int {
		cuenta++
		return cuenta
	}
}

func Aleatorio(semilla int64) Generador {
	rnd := rand.NewSource(semilla)
	return func() int {
		return int(rnd.Int63())
	}
}

func GeneradorTodo(gens ...Generador) []int {
	nums := make([]int, 0, len(gens))

	for _, fg := range gens {
		nums = append(nums, fg())
	}
	return nums
}
