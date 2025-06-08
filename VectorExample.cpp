#include <cstdio>
#include <vector>

std::vector<long> v {0}; // Initialize vector with one element

int main(int, char**) {
	auto it = v.begin();
	// add elements w ith push_back
	v.push_back(1);
	// add elements with insert
	v.insert(it, 2);

	// access elements with iterators, but check the iterator is valid by comparing against end()
	if (it != v.end()) {
		printf("First element: %ld\n", *it);
	} else {
		printf("Vector is empty\n");
		return 1;
	}

	// Raw element access is unsafe
	printf("Second element: %ld\n", v[1]);
	// Use at() for bounds checking
	printf("Third element: %ld\n", v.at(2));
	return 0;
}