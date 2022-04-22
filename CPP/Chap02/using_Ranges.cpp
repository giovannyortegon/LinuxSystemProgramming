#include<vector>
#include<iostream>
#include<ranges>

int main() {
	auto temperatures = {28, 25, -8, -3, 15, 21, -1};
	auto minus = [] (int i) { return i <= 0; };
	auto toFahrenheit = [] (int i) { return (i * (9 / 5)) + 32; };

	for (int t: temperatures | std::views::filter(minus) |
		 std::views::transform(toFahrenheit))
		std::cout << t <<' ' <<std::endl;
}
