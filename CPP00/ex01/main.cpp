#include <iostream>
#include <string>
#include "PhoneBook.hpp"

std::string    input_manager(std::string line)
{
    std::string input;

    std::cout << line;
    std::getline(std::cin, input);
    return (input);
}

void    add(PhoneBook &phonebook)
{
    Contact contact;
    std::string input;

    input = input_manager("Please input First Name: ");
    contact.setFirstName(input);
    input = input_manager("Please input Last Name: ");
    contact.setLastName(input);
    input = input_manager("Please input Nickname: ");
    contact.setNickname(input);
    input = input_manager("Please input Phone: ");
    contact.setPhoneNumber(input);
    input = input_manager("Please input Secret: ");
    contact.setDarkestSecret(input);
    std::cout << contact.getLastName() << std::endl;
}

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
            add(phonebook);
        else if (input == "SEARCH")
            std::cout << "Indeed I do something dope" << std::endl;
        else
            std::cout << "This command is not valid, please redo" << std::endl;
    }
}