#include "Contact.hpp"

Contact::Contact():_first_name("Default"), _last_name("Default"), _nickname("Default"), _phone_number("66666666"), _darkest_secret("POTAOTE")
{
    return;
}

Contact::~Contact()
{
    return;
}

std::string Contact::getFirstName() const
{
    return _first_name;
}

std::string Contact::getLastName() const
{
    return _last_name;
}

std::string Contact::getNickname() const 
{
    return _nickname;
}

std::string Contact::getPhoneNumber() const
{
    return _phone_number;
}

std::string Contact::getDarkestSecret() const
{
    return _darkest_secret;
}

void Contact::setFirstName(const std::string& first_name)
{
    _first_name = first_name;
}

void Contact::setLastName(const std::string& last_name)
{
    _last_name = last_name;
}

void Contact::setNickname(const std::string& nickname)
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phonenumber)
{
    _phone_number = phonenumber;
}

void Contact::setDarkestSecret(const std::string& darkest_secret)
{
    _darkest_secret = darkest_secret;
}
