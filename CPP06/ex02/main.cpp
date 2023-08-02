
#include "Base.hpp"

Base *generate(void) {
	srand(time(0));
	int switcher = rand() % 3;
	if (switcher == 0)
		return new A;
	else if (switcher == 1)
		return new B;
	else if (switcher == 2)
		return new C;
	return (NULL);
}

void identify(Base *p) {}

void identify(Base &p) {}

int main() {
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
}