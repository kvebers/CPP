
#include "ExtraSort.tpp"
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: Need at least 1 positive integer" << std::endl;
		return 0;
	}
	try {
		PmergeMe pmerge(argv, argc);
		pmerge.start();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	// system("leaks PmergeMe");
}