#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	std::vector<int> v {1, 2, 3, 4, 5, 6};
	std::string prefix ("0");
//	[] (int x);

	for_each(begin(v), end(v), [] (int x) -> std::vector<int> {
			if (x % 2)
				return {1, 2};
			else
				return {3, 4};
			std::cout <<std::endl <<x;
	});

	for_each(begin(v), end(v), [&prefix](int x) {
		std::cout <<prefix <<x <<std::endl;
	});
}
