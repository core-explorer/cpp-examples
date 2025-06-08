#include <signal.h>
#include <cstdio>
#include <cstdlib>

struct FibonacciResult {
	FibonacciResult* previous_previous = nullptr;
	FibonacciResult* previous = nullptr;

	FibonacciResult() = default;
	FibonacciResult(FibonacciResult* a, FibonacciResult* b) :
	    previous_previous(a), previous(b) {}

	long compute() {
		if (previous_previous) {
			return previous->compute() + previous_previous->compute();
		} else if (previous) {
			return previous->compute();
		} else {
			return 1;
		}
	}
	~FibonacciResult() {
		// Clean up the previous results to avoid memory leaks
		delete previous_previous;
		delete previous;
	}
};

FibonacciResult zero;

auto make_fibonacci(long n) {
	if (n <= 0) {
		return &zero;
	} else if (n == 1) {
		return new FibonacciResult(nullptr, &zero);
	} else {
		return new FibonacciResult(make_fibonacci(n - 2), make_fibonacci(n - 1));
	}
}

int main(int argc, char** argv) {
	int n = 5;
	if (argc > 1) {
		n = std::atoi(argv[1]);
	}
	printf("Fibonacci sequence:\n");
	for (int i = (n == 0 ? 0 : 1); i <= n; ++i) {
		auto* fib = make_fibonacci(i);
		printf("%ld\n", fib->compute());
	}
	if (argc < 3) {
		raise(SIGTRAP);
	}

	return 0;
}