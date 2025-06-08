#include <csetjmp>
#include <cstdio>
#include <cstring>

// people used longjmp/setjmp before the invention of C++ exceptions
// to handle errors and unwinding the stack.
// This example demonstrates how to use setjmp/longjmp to handle an error

std::jmp_buf env;

void unreachable_code() {
	printf("This code will never be reached!\n");
}

void unwindable_function() {
	// Simulate some processing
	memset(&env, 'A', sizeof(env));

	// Jumps back to main
	std::longjmp(env, 1);

	// This code will not be executed after longjmp
	unreachable_code();
}

int main() {
	if (setjmp(env) == 0) {
		unwindable_function();
	} else {
		printf("Returned to main via longjmp!\n");
	}
	return 0;
}
