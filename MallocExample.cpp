#include <signal.h>
#include <cstdio>
#include <cstdlib>

long zero = 0;

// See the NewExample for modern C++ memory management

auto fibonacci(long n) {
	if (n <= 0) {
		return &zero;
	} else if (n == 1) {
		auto ptr = reinterpret_cast<long*>(malloc(sizeof(long)));
		*ptr = 1;
		return ptr;
	} else {
		long a = *fibonacci(n - 1);
		long b = *fibonacci(n - 2);

		auto ptr = reinterpret_cast<long*>(malloc(sizeof(long)));
		*ptr = a + b;
		return ptr;
	}
}

int main(int argc, char** argv) {
	int n = 5;
	if (argc > 1) {
		n = std::atoi(argv[1]);
	}
	printf("Fibonacci sequence:\n");
	for (int i = (n == 0 ? 0 : 1); i <= n; ++i) {
		long* fib = fibonacci(i);
		printf("%ld\n", *fib);
		// Free the allocated memory to avoid memory leaks
		free(fib);
	}
	if (argc < 3) {
		raise(SIGTRAP);
	}

	return 0;
}