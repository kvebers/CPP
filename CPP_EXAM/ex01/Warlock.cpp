#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock &Warlock::operator=(Warlock const &other) {
	_name = other._name;
	_title = other._title;
	return *this;
}

Warlock::Warlock(Warlock const &other) { *this = other; }

Warlock::Warlock(std::string name, std::string title) : _title(title), _name(name) {
	std::cout << _name << ": his looks like another boring day." << std::endl;
}
Warlock::~Warlock() { std::cout << _name << ": My job here is done" << std::endl; }
std::string const &Warlock::getName() const { return _name; }
std::string const &Warlock::getTitle() const { return _title; }
void Warlock::setTitle(std::string const &string) { _title = string; }
void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}