#include <cstdio>

// this function is defined in another file
void fill_array_backwards(size_t* p, int size);

int main(int, char**) {
	// C arrays are faster than STL arrays in compilation
	size_t a[5] = {1, 2, 3, 4, 5};
	// trick to get size of array
	fill_array_backwards(a, sizeof(a) / sizeof(a[0]));
	for (auto i : a) {
		printf("%lu\n", i);
	}
	return 0;
}