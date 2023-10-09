#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ASpell {
   protected:
	std::string _name;
	std::string _effect;

   public:
	ASpell(std::string name, std::string effect);
	ASpell &operator=(ASpell const &other);
	ASpell(ASpell const &other);
	virtual ~ASpell;
	std::string getName() const;
	std::string getEffect() const;
	virtual ASpell *clone() const = 0;
	void lunch(ATarget const &target) const;

   private:
};

#endif