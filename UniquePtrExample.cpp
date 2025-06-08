#include <cerrno>
#include <cstdio>
#include <memory>
struct PS3 {
	virtual ~PS3() {}
	// chosen by fair dice roll, guaranteed to be random
	virtual int getRandomNumber() { return 4; }
};

struct PS4 {
	// use a memory address as a random number
	size_t value = (size_t)&errno;

	int getRandomNumber() { return value; }
};

int main() {
	// this is a C-style unsafe raw pointer
	PS3* raw_ptr;
	// initialize it to nullptr to be safe
	raw_ptr = nullptr;
	// we can use a unique_ptr that manages memory for us and get a raw pointer from it
	raw_ptr = std::unique_ptr<PS3>(new PS3).get();

	// even better is to use std::make_unique which is safer and cleaner
	auto b = std::make_unique<PS4>();
	// you can use a unique_ptr just like a raw ptr
	printf("random numbers: %d %d\n", raw_ptr->getRandomNumber(), b->getRandomNumber());

	return 0;
}