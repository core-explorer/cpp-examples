#include <cstddef>

void fill_array(size_t* start_ptr, int n) {
	// This is a pointer to the start of the array
	for (int i = 0; i < n; ++i) {
		// array indices start at zero
		start_ptr[i] = i;
	}
}

void fill_array_backwards(size_t* end_ptr, int n) {
	// This is a pointer to the end of the array
	for (int i = 0; i < n; ++i) {
		// we need to subtract 1 from the pointer to get the last element
		// and then subtract i to get the ith element from the end
		end_ptr[-(i + 1)] = i;
	}
}
