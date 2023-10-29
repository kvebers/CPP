#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class ATarget {
protected:
  std::string type;
  ATarget();
  ATarget(ATarget const &other);
  ATarget &operator=(ATarget const &other);

public:
  ATarget(std::string const &other);
  virtual ~ATarget();

  std::string const &getType() const;
  virtual ATarget *clone() const = 0;
  void getHitBySpell(ASpell const &spell) const;
};

#endif