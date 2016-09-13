#include <quicksort.h>
#include <thread>

namespace parallel {

void QuickSort::parallel(std::function<void(void)> fn1, std::function<void(void)> fn2)
{
	std::thread thread(fn1);
	fn2();
	thread.join();
}

}
