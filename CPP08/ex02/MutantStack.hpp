#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <list>
#include <stack>

template <typename STACK>
class MutantStack : public std::stack<STACK> {
	// Orthodox form, just using the inherited functions from the std::stack
   public:
	MutantStack() : std::stack<STACK>() {}
	~MutantStack() {}
	MutantStack(const MutantStack &idk) : std::stack<STACK>(idk) {}
	MutantStack &operator=(const MutantStack &idk) {
		if (this == &idk) return *this;
		std::stack<STACK>::operator=(idk);
		return *this;
	}
	// functions that i need to implement
	typedef typename std::stack<STACK>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }  // FOR some reason I can not acces the c valie
	iterator end() { return this->c.end(); }

   private:
	// There is

	// pop

	// empty

	// size

	//

	// top

	// push

	// pop
};

#endif