#include "RPN.hpp"

#include <cctype>
#include <exception>
#include <stdexcept>
#include <string>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(std::string &input) : _input(input) {}

RPN &RPN::operator=(const RPN &idk) {
	if (this == &idk) return *this;
	_input = idk._input;
	return *this;
}

RPN::RPN(const RPN &idk) : _input(idk._input) {}

int RPN::doTheOps(int operator1, int operator2, char token) {
	if (token == '-') return (operator2 - operator1);
	if (token == '+') return (operator2 + operator1);
	if (token == '*') return (operator2 * operator1);
	if (token == '/') return (operator2 / operator1);
	throw std::logic_error("Something is not correct here");
	return (0);
}

void RPN::doTheMath(char token) {
	if (token != '/' && token != '*' && token != '+' && token != '-') {
		theStack.push(token - '0');
	} else {
		if (theStack.size() < 2) throw std::logic_error("Error: Math logic error");
		int operator1 = theStack.top();
		theStack.pop();
		int operator2 = theStack.top();
		theStack.pop();
		theStack.push(doTheOps(operator1, operator2, token));
	}
}

void RPN::stackInit() {
	int counter = 0;
	bool space = true;
	for (int cnt = 0; cnt < _input.size(); cnt++) {
		if (!std::isdigit(_input[cnt]) && _input[cnt] != '+' && _input[cnt] != '-' &&
			_input[cnt] != ' ' && _input[cnt] != '*' && _input[cnt] != '/')
			throw std::logic_error("Error: Wrong input");
		if (_input[cnt] != ' ' && space == true) {
			if (std::isdigit(_input[cnt])) counter++;
			space = false;
			doTheMath(_input[cnt]);
		} else if (space == false) {
			space = true;
		} else {
			throw std::logic_error("Error: I do not like that many spaces in my input");
		}
		if (counter > 10) throw std::logic_error("Error: There is too many digits");
	}
	if (theStack.size() == 1)
		std::cout << theStack.top() << std::endl;
	else
		throw std::logic_error("Errror: Incorrect input");
}

void RPN::start() { stackInit(); }