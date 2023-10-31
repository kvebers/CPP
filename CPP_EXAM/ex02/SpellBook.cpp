#include "SpellBook.hpp"

#include <iostream>

SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &other) {
	size_t i = spells.size();
	while (i-- > 0) delete spells[i];
	spells.clear();
	i = 0;
	while (i++ < other.spells.size()) spells.push_back(other.spells[i]->clone());
}

SpellBook &SpellBook::operator=(SpellBook const &other) {
	if (this != &other) {
		size_t i = spells.size();
		while (i-- > 0) delete spells[i];
		spells.clear();
		i = 0;
		while (i++ < other.spells.size()) spells.push_back(other.spells[i]->clone());
	}
	return *this;
}

SpellBook::~SpellBook() {
	size_t i = spells.size();
	while (i-- > 0) delete spells[i];
	spells.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
	size_t i = spells.size();
	while (i-- > 0)
		if (spells[i]->getName().compare(spell->getName()) == 0) return;
	spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &spell) {
	size_t i = spells.size();
	while (i-- > 0) {
		if (spells[i]->getName().compare(spell) == 0) {
			delete spells[i];
			spells.erase(spells.begin() + i);
			return;
		}
	}
}

ASpell *SpellBook::createSpell(std::string const &spell) {
	size_t i = spells.size();
	while (i-- > 0)
		if (spells[i]->getName().compare(spell) == 0) return spells[i];
	return (NULL);
}
