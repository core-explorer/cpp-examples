#include <cstdio>

/**
 * Example showing how to use pointers correctly in C++
 */

struct Type {
	// Always initialize member variables
	Type(int c) :
	    a(c), b(c) {}
	int a;
	int b;
};

void ifunc(const int* p) {
	if (not p) {
		/* It is important to check for null pointers before dereferencing to avoid undefined behavior (UB) */
		printf("Error: null pointer\n");
		return;
	}
	printf("Integer value: %d\n", *p);
}

template <typename T>
void ufunc(T&& ptr) {
	// This is a perfect forwarding reference
	// ptr will be a pointer even if it looks like a reference

	// Access members by using the -> operator
	auto& b = ptr->b;
	// create pointer from reference by using address of operator
	auto* p = &b;
	ifunc(p);
}

void pfunc(Type* ptr) {
	ufunc(ptr);
}
// Variables on global scope are automatically initialized to zero
Type* t;
int main(int, char**) {
	if (t == nullptr) {
		// Initialize t
		Type* t = new Type(1);
		t->b = 2;
	}
	// This will print "Integer value: 2"
	pfunc(t);
	// Free to avoid memory leak
	delete t;
	return 0;
}