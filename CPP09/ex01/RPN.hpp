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
	void doTheMath(char token);
	int doTheOps(int operator1, int operator2, char token);

   private:
	std::string _input;
	int _result;
	std::stack<int> theStack;
};

#endif