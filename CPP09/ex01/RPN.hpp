#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <stack>
#include <stdexcept>

class RPN {
   public:
	RPN();
	RPN(std::string &input);
	~RPN();
	RPN &operator=(const RPN &idk);
	RPN(const RPN &idk);
	void start();
	void stackInit();
	void doTheMeth();
	void checkKindergardenMeth();

   private:
	std::string _input;
	std::stack<char> theStack;
};

#endif