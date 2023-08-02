
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(time(0));
	int switcher = rand() % 3;
	if (switcher == 0) {std::cout << "Generated A " << std::endl; return new A; }
	else if (switcher == 1) {std::cout << "Generated B " << std::endl; return new B; }
	else if (switcher == 2) {std::cout << "Generated C " << std::endl; return new C; }
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) std::cout << "PTR : A" << std::endl;
	else if (dynamic_cast<B *>(p)) std::cout << "PTR : B" << std::endl;
	else if (dynamic_cast<C *>(p)) std::cout << "PTR : C" << std::endl;
	else std::cout << "PTR: Code dose not work for some reason" << std::endl;
}

void identify(Base &p) {
	if (dynamic_cast<A *>(&p)) std::cout << "ADRESS : A" << std::endl;
	else if (dynamic_cast<B *>(&p)) std::cout << "ADRESS : B" << std::endl;
	else if (dynamic_cast<C *>(&p)) std::cout << "ADRESS : C" << std::endl;
	else std::cout << "PTR: Code dose not work for some reason" << std::endl;
}

int main() {
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
}