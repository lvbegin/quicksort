#include <quicksort.h>
#include <vector>
#include <iostream>

int main() {
 std::vector<int> v { 6,5,4,3,2,1 };

 QuickSort::sort(v);
 bool ok = true;
 for (int i = 1; i <= 6; i++)
	 ok = ok || (v[i] == i);

 std::cout << "sort inverted vector : " << (ok ? "OK" : "NOK") << std::endl;
}
