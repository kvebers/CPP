#include "Warlock.hpp"

#include "ASpell.hpp"

Warlock::Warlock(std::string const &n, std::string const &t) : name(n), title(t) {
	std::cout << n << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &other) {
	name = other.name;
	title = other.title;

	size_t i = spells.size();
	while (i-- > 0) delete spells.at(i);
	spells.clear();
	i = 0;
	while (i++ < other.spells.size()) spells.push_back(other.spells.at(i)->clone());
}

Warlock::Warlock() : name(""), title("") {}

Warlock::~Warlock() {
	std::cout << name << ": My job here is done!" << std::endl;
	size_t i = spells.size();
	while (i-- > 0) delete spells.at(i);
	spells.clear();
}

Warlock &Warlock::operator=(Warlock const &other) {
	if (this != &other) {
		name = other.name;
		title = other.title;
		size_t i = spells.size();
		while (i-- > 0) delete spells.at(i);
		spells.clear();
		while (i++ < other.spells.size()) spells.push_back(other.spells.at(i)->clone());
	}
	return *this;
}

std::string const &Warlock::getName() const { return name; }
std::string const &Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const &t) { title = t; }

void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
	size_t i = spells.size();
	while (i-- > 0) {
		if (spells.at(i)->getName().compare(spell->getName()) == 0) return;
	}
	spells.push_back(spell->clone());
}

void Warlock::forgetSpell(std::string spellName) {
	size_t i = spells.size();
	while (i-- > 0) {
		if (spells.at(i)->getName().compare(spellName) == 0) {
			delete spells.at(i);
			spells.erase(spells.begin() + i);
			return;
		}
	}
}

void Warlock::launchSpell(std::string spellName, ATarget const &target) {
	size_t i = spells.size();
	while (i-- > 0) {
		if (spells.at(i)->getName().compare(spellName) == 0) {
			spells.at(i)->launch(target);
			return;
		}
	}
}