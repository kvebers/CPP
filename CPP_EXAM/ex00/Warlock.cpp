#include "Warlock.hpp"

Warlock::Warlock(std::string const &n, std::string const &t) : name(n), title(t) {
	std::cout << n << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &other) {
	name = other.name;
	title = other.title;
}

Warlock::Warlock() : name(""), title("") {}

Warlock::~Warlock() { std::cout << name << ": My job here is done!" << std::endl; }

Warlock &Warlock::operator=(Warlock const &other) {
	if (this != &other) {
		name = other.name;
		title = other.title;
	}
	return *this;
}

std::string const &Warlock::getName() const { return name; }
std::string const &Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const &t) { title = t; }

void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}