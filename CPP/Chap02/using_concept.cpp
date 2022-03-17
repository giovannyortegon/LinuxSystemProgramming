#include<algorithm>
#include<concepts>

namespace sp {
	template<typename T>
		requires Sortable<T>
	void sort(T &container) {
		std::sort(begin(container), end(container));
	};
}

int main() {
	std::vector<int> myVec {2, 1, 4, 3};
	sp::sort(vec);

	return (0);
}
