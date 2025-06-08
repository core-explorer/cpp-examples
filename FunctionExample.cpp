#include <cstdio>

int function(int arg1, unsigned arg2);
typedef int FunctionType(int arg1, unsigned arg2);

FunctionType* func_ptr;

int main(int argc, char**) {
	int ret = func_ptr(argc, 2u);
	return ret;
}
