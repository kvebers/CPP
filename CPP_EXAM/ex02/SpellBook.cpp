#include "SpellBook.hpp"

#include <cstddef>

SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &other) {
	size_t i;

	i = spells.size();
	while (i-- > 0) delete spells.at(i);

	spells.clear();

	i = 0;
	while (i++ < other.spells.size()) spells.push_back(other.spells.at(i)->clone());
}

SpellBook &SpellBook::operator=(SpellBook const &other) {
	if (this != &other) {
		size_t i;

		i = spells.size();
		while (i-- > 0) delete spells.at(i);

		spells.clear();

		i = 0;
		while (i++ < other.spells.size()) spells.push_back(other.spells.at(i)->clone());
	}
	return *this;
}

SpellBook::~SpellBook() {
	size_t i;

	i = spells.size();
	while (i-- > 0) delete spells.at(i);

	spells.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
	size_t i;

	i = spells.size();
	while (i-- > 0) {
		if (spells.at(i)->getName().compare(spell->getName()) == 0) return;
	}

	spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &spellName) {
	size_t i;

	i = spells.size();
	while (i-- > 0) {
		if (spells.at(i)->getName().compare(spellName) == 0) {
			delete spells.at(i);
			spells.erase(spells.begin() + i);
			return;
		}
	}
}

ASpell *SpellBook::createSpell(std::string const &spellName) {
	size_t i;

	i = spells.size();
	while (i-- > 0) {
		if (spells.at(i)->getName().compare(spellName) == 0) return (spells.at(i));
	}
	return (NULL);
}
