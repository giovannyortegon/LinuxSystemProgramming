#include<iostream>
#include<vector>
#include<array>
#include<span>

void print(std::span<int> container) {
	for (const auto &c: container)
		std::cout <<c << "-";
}

int main() {
	int elems[] {4, 2, 43, 12};
	print(elems);
	std::vector vElems {4, 2, 43, 12}
	print(vElems)
}
