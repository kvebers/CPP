#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {
   private:
	Warlock();
    Warlock &operator=(Warlock const &other);
    Warlock(Warlock const &other);
    std::string _title;
    std::string _name;

   public:
	Warlock(std::string name, std::string title);
    ~Warlock();
    std::string const &getName() const;
    std::string const &getTitle() const;
    void setTitle(std::string const & string);
    void introduce() const;
};

#endif