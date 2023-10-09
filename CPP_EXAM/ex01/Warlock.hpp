#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <algorithm>
#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock {
   private:
	Warlock();
	Warlock &operator=(Warlock const &other);
	Warlock(Warlock const &other);
	std::string _title;
	std::string _name;
	std::map<std::string, ASpell *> _SpellBook;

   public:
	Warlock(std::string name, std::string title);
	~Warlock();
	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &string);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string SpellName);
	void launchSpell(std::string SpellName, ATarget &target);
};

#endif