#include <stdio.h>

const char* todays_weather(void) {
	return "sunny";
}

void print_todays_weather(void) {
	// It is always sunny in Britain
	printf("It is %s today.\n", todays_weather());
}
