package main

import (
	"fmt"
	"time"
)

type Estudiante struct {
	nombre     string
	nacimiento time.Time
	descuento  bool
}

type Opcion func(*Estudiante)

func main() {
	estu0 := NewEstudiante()
	estu1 := NewEstudiante(Nombre("Pedro"), Descuento(true))
	estu2 := NewEstudiante(Nombre("Juan"), Nacimiento(time.Date(2001, 10, 12, 0, 0, 0, 0, time.UTC)))

	fmt.Println(estu0)
	fmt.Println(estu1)
	fmt.Println(estu2)
}

func Nombre(nombre string) Opcion {
	return func(std *Estudiante) {
		std.nombre = nombre
	}
}

func Nacimiento(nacimiento time.Time) Opcion {
	return func(std *Estudiante) {
		std.nacimiento = nacimiento
	}
}

func Descuento(descuento bool) Opcion {
	return func(std *Estudiante) {
		std.descuento = descuento
	}
}

func NewEstudiante(opciones ...Opcion) Estudiante {
	estudiante := Estudiante{
		nombre: "desconocido",
	}

	for _, opcion := range opciones {
		opcion(&estudiante)
	}

	return estudiante
}
