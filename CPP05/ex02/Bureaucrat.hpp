#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#include "AForm.hpp"
class AForm;

class Bureaucrat {
   public:
	// ORTHODOX STUFF
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &word_i_can_spell);
	Bureaucrat(const Bureaucrat &word_i_can_spell);
	Bureaucrat(std::string name, int grade);
	// getters
	const std::string &getName() const;
	int getGrade() const;
	// functions
	void decrementGrade();
	void incrementGrade();
	void signForm(AForm &aform);
	void executeForm(AForm const &aform) const;

	class GradeTooLowException : public std::exception {
	   public:
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &word_i_can_spell);

#endif