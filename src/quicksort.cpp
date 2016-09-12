#include <quicksort.h>
#include <thread>

namespace QuickSort {

typedef struct integer_pair_s {
	size_t i;
	size_t j;
	integer_pair_s(size_t firstValue, size_t secondValue) : i(firstValue), j(secondValue) { };
} integer_pair_s;

static void SortSubVector(std::vector<int> &v, integer_pair_s limits);
static void parallel(std::function<void(void)> fn1, std::function<void(void)> fn2);
static integer_pair_s findElemToSwap(std::vector<int> &v, integer_pair_s to_swap, size_t pivot);

void sort(std::vector<int> &v) { SortSubVector(v, integer_pair_s(0, v.size() - 1 )); }

static inline void swap_value(int &a, int &b) { const auto tmp = a; a = b; b = tmp; }

static void SortSubVector(std::vector<int> &v, integer_pair_s limits) {
	if (limits.i >= limits.j)
		return ;
	const size_t mid = limits.i + ((limits.j - limits.i + 1) / 2);
	auto indexes = findElemToSwap(v, limits, mid);
	for (; indexes.i < indexes.j; indexes = findElemToSwap(v, indexes, mid))
		swap_value(v[indexes.i], v[indexes.j]);
	swap_value(v[indexes.i], v[mid]);
	parallel([&](void) { SortSubVector(v, integer_pair_s(limits.i, indexes.i - 1)); },
			 [&](void) { SortSubVector(v, integer_pair_s(indexes.i + 1, limits.j)); });
}

static integer_pair_s findElemToSwap(std::vector<int> &v, integer_pair_s to_swap, size_t pivot) {
	while (v[to_swap.i] <= v[pivot] && to_swap.i < to_swap.j) to_swap.i++;
	while (v[to_swap.j] >= v[pivot] && to_swap.i < to_swap.j) to_swap.j--;
	return to_swap;
}

static void parallel(std::function<void(void)> fn1, std::function<void(void)> fn2)
{
	std::thread thread(fn1);
	fn2();
	thread.join();
}

}
