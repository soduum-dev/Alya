#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

std::string home;
// std::string args_10[10];

#include "think.cpp"

int main(int argc, char* argv[]) { 	if (argc == 2) { if (argc == 1){ std::cout << "Hi! "; return 1; } else{ std::cout << "What?\n"; return 1; } } // if args not given 
					else { if (argc > 10) {std::cout << "\tTOO MUCH  >.<\n"; exit(255); } }
	std::string arguments[argc];
	for (int i = 0; i < argc; i++) {
		arguments[i] = argv[i];	
	} // make args like std::string
	
	home = std::getenv("HOME"); home.push_back('/'); 
	// get home dir
	
	if (arguments[1] == "alias") { // if command alias
		if (argc >= 4) { aliase(arguments); } // check if command is not full
		else {
			std::cout 
				<< "you should give me full command\nAlya command(alias) \"alias\" \"full command\"\n"; }
	} else if (arguments[1] == "aliases") {
		if (argc >= 4) {
			aliases(arguments); 
		} else {
			std::cout << "full command pls\n";
		}
	} 
	else if (arguments[1] == "prj") {
	
		if (argc >= 5) {
			// make project dir.
		} 
		else { std::cout 
			<< "tell me more about this project: alya prj [name] [license] [number tree of prj]\nto know about trees of project run \"alya about tree\"\n"; }
	} 
	else { std::cout << "i dont know that command\n"; }
	
}
