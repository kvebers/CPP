#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _cnt;
    public:
        PhoneBook();
        ~PhoneBook();
};

#endif