#include "ASpell.hpp"

ASpell::ASpell(std::string const &initName, std::string const &initEffects)
	: name(initName), effects(initEffects){};

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
