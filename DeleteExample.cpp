#include <signal.h>
#include <memory>
struct MemoryManager {
	long* small = nullptr;
	long* medium = nullptr;
	long* large = nullptr;

	void allocateMemory() {
		small = new long[10]; // Small allocation
		medium = new long[100]; // Medium allocation
		large = new long[1000]; // Large allocation
	}
	void deallocateMemory() {
		delete[] small; // Deallocate small memory
		delete[] medium; // Deallocate medium memory
		delete[] large; // Deallocate large memory
	}
};

int main(int, char**) {
	auto manager = std::make_unique<MemoryManager>();
	manager->allocateMemory();
	manager->deallocateMemory();
	raise(SIGTRAP);

	return 0;
}