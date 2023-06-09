#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
   public:
	// ORTHODOX STUFF
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &word_i_can_spell);
	Bureaucrat(const Bureaucrat &word_i_can_spell);
	Bureaucrat(std::string name, int grade);
	void decrementGrade();
	void incrementGrade();
	int getGrade() const;
	const std::string &getName() const;

	class GradeTooLowException : public std::exception {
	   public:
		const char *error() const throw();
	};
	class GradeTooHighException : public std::exception {
	   public:
		const char *error() const throw();
	};

   private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &word_i_can_spell);

#endif