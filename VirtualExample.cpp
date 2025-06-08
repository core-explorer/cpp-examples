#include <cstdio>

class BaseClass {
public:
	// Constructor is never virtual
	BaseClass() {
		compute_value();
	}
	// Destructor should always be virtual
	virtual ~BaseClass() = default;

	// This function is not virtual
	void compute_value();
	// This function is pure virtual, derived classes must implement it
	virtual void compute_details() = 0;

	const int& getValue() const {
		return value;
	}

protected:
	int value;
};

void BaseClass::compute_value() {
	compute_details();
}

class DerivedClass : public BaseClass {
public:
	void compute_details() override {
		value = 42;
	}
};

int main() {
	DerivedClass d;
	// This prints "Value: 42"
	printf("Value: %d\n", d.getValue());
	return 0;
}