#pragma once

#include <iostream>
#include <stdexcept>


class Bureaucrat
{
	private:
		const std::string	name;
		short int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string s);
		Bureaucrat(Bureaucrat &val);
		Bureaucrat& operator=(Bureaucrat &val);
		~Bureaucrat();

		// getters
		std::string	getName();
		short int	getGrade();

		// member functions
		void	gradeIncrement();
		void	gradeDecrement();
		

		// exceptions
		class GradeTooHighException: public std::exception
		{
				public:
						const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
				public:
						const char* what() const throw();
		};
};


std::ostream& operator<<(std::ostream& out, Bureaucrat& cls);
