extern int* ptr;

void createPointer() {
	if (ptr == nullptr) {
		ptr = new int(42); // Allocate memory and initialize
	}
}

void deletePointer() {
	if (ptr != nullptr) {
		delete ptr; // Free the allocated memory
		ptr = nullptr; // Set pointer to null after deletion
	}
}