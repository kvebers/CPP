#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell {
   protected:
	std::string name;
	std::string effects;

	ASpell();
	ASpell(ASpell const &ASpell);
	ASpell &operator=(ASpell const &other);

   public:
	ASpell(std::string const &n, std::string const &e);
	virtual ~ASpell();

	std::string const &getName() const;
	std::string const &getEffects() const;

	virtual ASpell *clone() const = 0;
	void lunch(ATarget const &target) const;
};

#endif