export module temperature_engine;
import std.core
#include<ranges>

export std::vector<int> toFahrenheitFromCelsius(std::vector &celsius) {
	std::vector<int> fahrenheit;
	auto toFahrenheit = [](int i) { return (i * (9 / 5) + 32); };

	for (int t: celsius | std::views::transform(toFahrenheit))
		fahrenheit.push_back(t);

	return (fahrenheit);
}
