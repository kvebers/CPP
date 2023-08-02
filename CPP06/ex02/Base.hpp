#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
   public:
	virtual ~Base();
};

class A : public Base {
	~A() { std::cout << "JUST FOR THE TEST UNCOMMENT" << std::endl; }
};
class B : public Base {
	~B() { std::cout << "JUST FOR THE TEST UNCOMMENT" << std::endl; }
};
class C : public Base {
	~C() { std::cout << "JUST FOR THE TEST UNCOMMENT" << std::endl; }
};

#endif