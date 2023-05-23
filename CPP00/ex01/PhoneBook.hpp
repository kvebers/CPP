#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _cnt;
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        int     getTotal ();
        void    searchContact();
};

#endif