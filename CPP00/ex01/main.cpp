#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"

int main()
{
    int exit = 0;
    std::string input;
    PhoneBook phonebook = PhoneBook();

    while (exit != 1)
    {
        std::cout << "Use commands ADD, SEARCH, EXIT: ";
        std::getline(std::cin, input);

        if (input == "EXIT")
            exit = 1;
        else if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
        {
            phonebook.searchContact();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            std::cout << "This command is not valid, please redo" << std::endl;
    }
}