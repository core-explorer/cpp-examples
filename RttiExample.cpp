#include "Implementation.h"
#include "Interface.h"
#include <cstdio>
#include <memory>

class Implementation2 : public Interface {
public:
	virtual ~Implementation2() {}
	void doSomething() override {
		printf("doSomething() in Implementation2!\n");
	}

	// Derived classes can add extra functionality
	virtual void doSomeMore2() {
		printf(" doSomethingMore2() in Implementation2!\n");
	}
};

std::unique_ptr<Interface> createObject();

int main() {
	auto obj = createObject();
	obj->doSomething();
	// use dynamic_cast to safely check if the object is of type Implementation
	if (auto ptr = dynamic_cast<Implementation*>(obj.get()); ptr) {
		ptr->doSomeMore();
	}

	auto ob2 = Implementation2();
	auto& if2 = static_cast<Interface&>(ob2);
	if2.doSomething();
	try {
		// dynamic_cast on a reference is never zero, but may throw
		auto& impl2 = dynamic_cast<Implementation2&>(if2);
		impl2.doSomeMore2();
	} catch (const std::bad_cast& e) {
		printf("Caught bad_cast: %s\n", e.what());
	}

	return 0;
}