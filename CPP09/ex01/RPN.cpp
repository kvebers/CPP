#include "RPN.hpp"

#include <cctype>
#include <stdexcept>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(std::string &input) : _input(input) {}

RPN &RPN::operator=(const RPN &idk) {
	if (this == &idk) return *this;
	_input = idk._input;
	return *this;
}

RPN::RPN(const RPN &idk) : _input(idk._input) {}

void RPN::stackInit() {
	int cnt = 0;
	bool space = true;
	for (int cnt = 0; cnt < _input.size(); cnt++) {
		if (!std::isdigit(_input[cnt]) && _input[cnt] != '+' && _input[cnt] != '-' &&
			_input[cnt] != ' ' && _input[cnt] != '*' && _input[cnt] != '/')
			throw std::logic_error("Error: Wrong input");
		if (_input[cnt] != ' ' && space == true) {
			if (std::isdigit(_input[cnt])) cnt++;
			theStack.push(_input[cnt]);
		} else if (space == false) {
			space = true;
		} else {
			throw std::logic_error("Error: I do not like that many spaces in my input");
		}
		if (cnt > 10) throw std::logic_error("Error: There is too many digits");
	}
}

void RPN::checkKindergardenMeth() { return; }

void RPN::doTheMeth() { return; }

void RPN::start() {
	stackInit();
	checkKindergardenMeth();
	doTheMeth();
}