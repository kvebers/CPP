#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "You SHALL NOT PASS" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	try {
		RPN rpn(input);
		rpn.start();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// system("leaks RPN");
}