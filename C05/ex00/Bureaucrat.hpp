#pragma once

#include <iostream>
#include <stdexcept>


class Bureaucrat
{
	private:
		std::string	name;
		short int	grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat &val);
		Bureaucrat& operator=(Bureaucrat &val);
		~Bureaucrat();

		// getters
		std::string	getName();
		short int	getGrade();

		//setters
		void	setName(std::string n);
		void	setGrade(short int g);

		// member functions
		void	gradeIncrement();
		void	gradeDecrement();
		

		// exceptions
		class GradeTooHighException: public std::exception
		{
				public:
						const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return "The grade is too high"; }
		};

		class GradeTooLowException: public std::exception
		{
				public:
						const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return "The grade is too low"; }
		};
};


std::ostream& operator<<(std::ostream& out, Bureaucrat& cls);
