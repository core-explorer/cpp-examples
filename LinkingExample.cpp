#include <cstdio>
extern int* ptr;
void createPointer();
void deletePointer();
inline int* getPtr() {
	if (ptr == nullptr) {
		createPointer();
	}
	return ptr;
}

int main() {
	int* myPtr = getPtr();
	printf("Pointer value: %p -> %i\n", (void*)myPtr, *myPtr); // Should print 42
	deletePointer(); // Clean up memory
	return 0;
}