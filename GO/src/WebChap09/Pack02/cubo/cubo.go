package cubo

func eleva3(x float64) float64 {
	return x * x * x
}

func Volumen(lado float64) float64 {
	return eleva3(lado)
}
