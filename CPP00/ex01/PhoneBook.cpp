#include "PhoneBook.hpp"

PhoneBook::PhoneBook ()
{
    _cnt = 0;
    return;
}

PhoneBook::~PhoneBook ()
{
    return;
}

int PhoneBook::getTotal ()
{
    return _cnt;
}

std::string    inputManager(std::string line)
{
    std::string input;

    std::cout << line;
    std::getline(std::cin, input);
    return (input);
}

void    PhoneBook::addContact()
{
    Contact contact;
    std::string input;
    int cnt;

    cnt = 0;
    input = inputManager("Please input First Name: ");
    contact.setFirstName(input);
    input = inputManager("Please input Last Name: ");
    contact.setLastName(input);
    input = inputManager("Please input Nickname: ");
    contact.setNickname(input);
    input = inputManager("Please input Phone: ");
    contact.setPhoneNumber(input);
    input = inputManager("Please input Secret: ");
    contact.setDarkestSecret(input);
    if (_cnt == 8) 
    {
        while (cnt < 7)
        {
           _contacts[cnt] = _contacts[cnt + 1];
            cnt++;
        }
        _contacts[cnt] = contact;
    }
    else 
    {
        _contacts[_cnt] = contact;
        _cnt++;
    }
}

void    PhoneBook::searchContact()
{
    int cnt;
    int input;

    cnt = 0;
    std::cout << "|";
    std::cout << std::right << std::setw(10) <<"Index" << "|";
    std::cout << std::right << std::setw(10) << "First Name" << "|";
    std::cout << std::right << std::setw(10) << "Last Name" << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
    while (cnt < _cnt)
    {
        std::cout << "|";
        std::cout << std::right << std::setw(10) << cnt + 1 << "|";
        if (_contacts[cnt].getFirstName().length() > 10)
            std::cout << std::right << std::setw(10) << _contacts[cnt].getFirstName().substr(0, 9) + ".";
        else
            std::cout << std::right << std::setw(10) << _contacts[cnt].getFirstName();
        std::cout << "|";
        if (_contacts[cnt].getLastName().length() > 10)
            std::cout << std::right << std::setw(10) << _contacts[cnt].getLastName().substr(0, 9) + ".";
        else
            std::cout << std::right << std::setw(10) << _contacts[cnt].getLastName();
        std::cout << "|";
        if (_contacts[cnt].getNickname().length() > 10)
            std::cout << std::right << std::setw(10) << _contacts[cnt].getNickname().substr(0, 9) + ".";
        else
            std::cout << std::right << std::setw(10) << _contacts[cnt].getNickname();
        std::cout << "|";
        std::cout<<std::endl;
        cnt++;
    }
    std::cout << "Input the Index of the Person: ";
    if (std::cin >> input) 
    {
        if (input - 1 < 0)
            std::cout << "Invalid input, do not add negatives" << std::endl;
        else if (input - 1 >= _cnt)
            std::cout << "Invalid input, phonebook dose not have that many numbers" << std::endl;
        else
        {
            std::cout << "First Name: " << _contacts[input - 1].getFirstName() << std::endl;
            std::cout << "Last Name: " << _contacts[input - 1].getLastName() << std::endl;
            std::cout << "Nickname: "  << _contacts[input - 1].getNickname() << std::endl;
            std::cout << "Phone: " << _contacts[input - 1].getPhoneNumber() << std::endl;
            std::cout << "Secret: " << _contacts[input - 1].getDarkestSecret() << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input, please add an integer" << std::endl;
        std::cin.clear();
    }
}
