#include <signal.h>
#include <cstdio>
#include <memory>
#include <string>
struct Hand {
	Hand(std::string n) :
	    name(std::move(n)) {}
	std::string name;
	std::shared_ptr<Hand> beats;
};

void showRules() {
	// shared_ptr will be cleaned up atomically just like unique_ptr, but can be copied
	std::shared_ptr<Hand> rock = std::make_shared<Hand>("Rock");
	std::shared_ptr<Hand> paper = std::shared_ptr<Hand>(new Hand("Paper"));
	std::shared_ptr<Hand> scissors = std::make_shared<Hand>("Scissors");
	rock->beats = scissors;
	paper->beats = rock;
	scissors->beats = paper;

	for (auto& h : {rock, paper, scissors}) {
		printf("%s beats %s\n", h->name.c_str(), h->beats->name.c_str());
	}
}

int main(int argc, char**) {
	showRules();
	if (argc <= 1) {
		raise(SIGTRAP);
	}
	return 0;
}
