#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
    private:
        std:: string _first_name;
        std:: string _last_name;
        std:: string _nickname;
        std:: string _phone_number;
        std:: string _darkest_secret;
    public:
        Contact ();
        ~Contact();
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
        void setFirstName(const std::string& first_name);
        void setLastName(const std::string& last_name);
        void setNickname(const std::string& nickname);
        void setPhoneNumber(const std::string& phonenumber);
        void setDarkestSecret(const std::string& darkest_secret);
};

#endif