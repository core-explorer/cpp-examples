
#include <signal.h>
extern "C" void print_todays_weather();

int main(int, char**) {
	print_todays_weather();

	raise(SIGTRAP);
	return 0;
}
