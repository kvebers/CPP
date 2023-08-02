#include "Base.hpp"

// ORTHODOC
Base::Base() { std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl; }
Base::~Base() { std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl; }
Base::Base(const Base &idk) { std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl; }
Base &Base::operator=(const Base &idk) {
	if (this != &idk) return *this;
	std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl;
	return *this;
}

// The Implementation

Base Base::*generate(void) {
    
}
void Base::Base::identify(Base *p) {}
void Base::Base::identify(Base &p) {}