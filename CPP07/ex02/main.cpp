#include <sys/errno.h>

#include <exception>

#include "Templates.hpp"
#define MAX_VAL 10

int main() {
  {
    std::cout << "TEST 1" << std::endl;
    try {
      Array<int> emptyArray;
      std::cout << "Position : " << emptyArray.find_first(3) << std::endl;
      std::cout << "Position : " << emptyArray.find_biggest() << std::endl;
      std::cout << "Print? " << emptyArray[0] << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "TEST 2" << std::endl;
    try {
      Array<int> emptyArray(0);
      std::cout << "Print? " << emptyArray[0] << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "TEST 3" << std::endl;
    try {
      Array<int> smollArray(5);
      smollArray[0] = 1;
      smollArray[1] = 2;
      smollArray[2] = 3;
      smollArray[3] = 4;
      smollArray[4] = 5;

      std::cout << "Size : " << smollArray.size() << std::endl;
      std::cout << "Position : " << smollArray.find_first(3) << std::endl;
      std::cout << "Position : " << smollArray.find_biggest() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      Array<int> smollArray(5);
      Array<int> emptyArray;
      smollArray[0] = 1;
      smollArray[1] = 2;
      smollArray[2] = 3;
      smollArray[3] = 4;
      smollArray[4] = 5;

      std::cout << "TEST 4" << std::endl;
      emptyArray = smollArray;
      std::cout << " Copy Assigment Test : " << emptyArray[0] << std::endl;
      std::cout << " Copy Assigment Test : " << emptyArray[4] << std::endl;
      std::cout << "TEST 5" << std::endl;
      Array<int> newArray(smollArray);
      std::cout << " Copy Test : " << emptyArray[0] << std::endl;
      std::cout << " Copy Test : " << emptyArray[4] << std::endl;
      // system("leaks Class_la_vista_baby");
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
