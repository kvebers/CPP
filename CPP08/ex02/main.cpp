#include "MutantStack.hpp"

int main() {
	{
		std::cout << "GIVEN TEST 1" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "GIVEN TEST REPLACED" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int, std::list<int> > s(mstack);
	}
	{
		MutantStack<int> mstack;
		mstack.push(2);
		mstack.push(4);
		mstack.push(3);
		mstack.push(5);
		std::cout << "START OF THE STACK : " << *mstack.begin()
				  << " END OF THE STACK : " << *mstack.end() << std::endl;
		MutantStack<int>::iterator iterator = mstack.begin();
		for (; iterator != mstack.end(); iterator++) {
			std::cout << "Adress : " << &(*iterator) << " The value :" << *iterator << std::endl;
		}
	}
}