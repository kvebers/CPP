#include "Warlock.hpp"

Warlock::Warlock(std::string const &initName, std::string const &initTitle)
	: name(initName), title(initTitle) {
	std::cout << initName << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &other) {
	name = other.name;
	title = other.title;
}

Warlock::Warlock() : name(""), title("") {}

Warlock::~Warlock() { std::cout << name << ": My job here is done!" << std::endl; }

Warlock &Warlock::operator=(const Warlock &other) {
	if (this != &other) {
		name = other.name;
		title = other.title;
	}
	return *this;
}

std::string const &Warlock::getName() const { return name; }
std::string const &Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const &newTitle) { title = newTitle; }

void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) { spellBook.learnSpell(spell); }

void Warlock::forgetSpell(std::string spellName) { spellBook.forgetSpell(spellName); }

void Warlock::launchSpell(std::string spellName, ATarget const &target) {
	ASpell *spell;

	spell = spellBook.createSpell(spellName);
	if (spell != NULL) spell->launch(target);
}
