#include "ASpell.hpp"

ASpell::ASpell(std::string const &n, std::string const &e)
	: name(n), effects(e){};

ASpell::ASpell() : name(""), effects("") {}

ASpell::ASpell(ASpell const &other) {
	name = other.name;
	effects = other.effects;
}

ASpell &ASpell::operator=(ASpell const &other) {
	if (this != &other) {
		name = other.name;
		effects = other.effects;
	}
	return *this;
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const { return name; }
std::string const &ASpell::getEffects() const { return effects; }

void ASpell::launch(ATarget const &target) const { target.getHitBySpell(*this); }
