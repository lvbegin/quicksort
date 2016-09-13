#ifndef PARALLEL_QUICKSORT_H__
#define PARALLEL_QUICKSORT_H__

#include <vector>
#include <cstddef>
#include <functional>

namespace parallel {

class QuickSort {
public:
	template <typename T>
	static void sort(std::vector<T> &v) { SortSubVector(v, integer_pair_s(0, v.size() - 1 )); }
private:
	typedef struct integer_pair_s {
		size_t i;
		size_t j;
		integer_pair_s(size_t firstValue, size_t secondValue) : i(firstValue), j(secondValue) { };
	} integer_pair_s;

	template <typename T>
	static inline void swap_value(T &a, T &b) { const auto tmp = a; a = b; b = tmp; }

	template <typename T>
	static void SortSubVector(std::vector<T> &v, integer_pair_s limits) {
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

	template <typename T>
	static integer_pair_s findElemToSwap(std::vector<T> &v, integer_pair_s to_swap, size_t pivot) {
		while (v[to_swap.i] <= v[pivot] && to_swap.i < to_swap.j) to_swap.i++;
		while (v[to_swap.j] >= v[pivot] && to_swap.i < to_swap.j) to_swap.j--;
		return to_swap;
	}

	static void parallel(std::function<void(void)> fn1, std::function<void(void)> fn2);
};

}

#endif
