import temperature_engine;
import std.core;
#include<iostream>

int main() {
	auto celsius = {28, 25, -8, -3, 15, 21, -1};
	auto fahrenheit = toFahrenheitFromCelsius(celsius);

	std::for_each(std::begin(fahrenheit), std::end(fahrenheit), [&fahrenheit](int i) {
		std::cout << i << ";";
	});
}
