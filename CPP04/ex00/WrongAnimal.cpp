#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default") {
	std::cout << "Animal: \"" << _type << "\" Created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _type(name) {
	std::cout << "Animal: \"" << _type << "\" Created" << std::endl;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal disapeared" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal) : _type(wronganimal._type) {
	std::cout << "WrongAnimal copy made" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal) {
	if (this == &wronganimal) return *this;
	std::cout << "WrongAnimal Copy Assigned" << std::endl;
	_type = wronganimal._type;
	return *this;
}

// The functions that need to be implemented
// Also virtual can be implemented only in class specification that neet...
void WrongAnimal::makeSound() const {
	std::cout << "some random sound of a wronganimal" << std::endl;
}

std::string WrongAnimal::getType() const { return _type; }