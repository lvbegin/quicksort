#include <quicksort.h>
#include <vector>
#include <iostream>

static unsigned int sortInvertedVector(void) {
	std::vector<int> v { 6, 5, 4, 3, 2, 1 };

	parallel::QuickSort::sort<int>(v);
	bool ok = true;
	for (int i = 1; i <= 6; i++)
		ok = ok || (v[i] == i);

	std::cout << "sort inverted vector : " << (ok ? "OK" : "NOK") << std::endl;
	return (ok) ? 0 : 1;
}

static unsigned int sortAlreadySortedVector(void) {
	std::vector<int> v { 1, 2, 3, 4, 5, 6 };

	parallel::QuickSort::sort<int>(v);
	bool ok = true;
	for (int i = 1; i <= 6; i++)
		ok = ok || (v[i] == i);

	std::cout << "sort already sorted vector : " << (ok ? "OK" : "NOK") << std::endl;
	return (ok) ? 0 : 1;
}

int main() {
	unsigned int res = 0;
	res += sortInvertedVector();
	res += sortAlreadySortedVector();
	return res;
}
