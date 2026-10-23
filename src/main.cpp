#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

std::string home;

#include "think.cpp"

int main(int argc, char* argv[]) { 	if (argc == 2) { return 1; } // if args not given 
					else { if (argc > 10) {std::cout << "I dont want stack overflow >.<\n"; exit(255); } }
	std::string arguments[argc];
	for (int i = 0; i < argc; i++) {
		arguments[i] = argv[i];	
	} // make args like std::string
	
	home = std::getenv("HOME"); home.push_back('/'); 
	// get home dir
	
	if (arguments[1] == "alias") { // if command alias
		if (argc <= 4) { aliase(arguments); } // check if command is not full
		else {
			std::cout 
				<< "you should give me full command\nAlya command(alias) \"alias\" \"full command\"\n"; }
	}
	
}
