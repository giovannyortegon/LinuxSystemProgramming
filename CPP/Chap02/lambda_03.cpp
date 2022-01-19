#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> using_lambda(std::vector<int> v) {
	return {1, 1};
}

int main() {
	std::vector<int> v {1, 2, 3, 4, 5, 6};
	std::vector<int> result;

	result = using_lambda(v);

	for(int x: v) {
		std::cout <<x <<"\n";
	}

	std::cout<<std::endl;

	for_each(begin(v), end(v), [] (int x)-> std::vector<int> {
			if (x % 2)
				return {7, 8};
			else
				return {9, 10};

		std::cout <<x;
	});


//	for_each(begin(v), end(v), [](int x){
//		std::cout <<x <<std::endl;
//	});
//	for_each(begin(result), end(result), [](int x){
//		std::cout <<x <<std::endl;
//	});

	return (0);
}
