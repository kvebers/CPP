#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <vector>

#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
   private:
	std::string name;
	std::string title;

	SpellBook spellBook;

	Warlock();
	Warlock(const Warlock &other);
	Warlock &operator=(const Warlock &other);

   public:
	Warlock(std::string const &initName, std::string const &initTitle);
	~Warlock();

	std::string const &getName() const;
	std::string const &getTitle() const;

	void setTitle(std::string const &newTitle);

	void introduce() const;

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget const &target);
};

#endif