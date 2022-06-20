package main

import "fmt"

type PH float32

func main() {
	phs := []PH{
		PH(7), PH(1.2), PH(9),
	}

	for _, ph := range phs {
		fmt.Printf("Un pH == %v es %v\n", ph, ph.Categoria())
	}
}

func (p PH) Categoria() string {
	switch {
	case p < 7:
		return "acido"
	case p > 7:
		return "basico"
	default:
		return "neutro"
	}
}
