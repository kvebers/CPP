#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
   public:
	Base();
	~Base();
	Base &operator=(const Base &idk);
	Base(const Base &idk);
	Base *generate(void);
	void identify(Base *p);
	void identify(Base &p);
};

#endif