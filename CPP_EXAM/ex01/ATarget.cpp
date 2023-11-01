#include "ATarget.hpp"

#include "ASpell.hpp"

ATarget::ATarget() : type("") {}

ATarget::ATarget(ATarget const &other) { type = other.type; }

ATarget &ATarget::operator=(ATarget const &other) {
	if (this != &other) type = other.type;
	return *this;
}

ATarget::~ATarget() {}

ATarget::ATarget(std::string const &t) : type(t) {}

std::string const &ATarget::getType() const { return type; }

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
