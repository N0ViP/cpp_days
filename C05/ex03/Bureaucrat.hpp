#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"


class Bureaucrat
{
	private:
		const std::string	name;
		short int	grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string s, const short int g);
		Bureaucrat(const Bureaucrat &val);
		Bureaucrat& operator=(const Bureaucrat &val);
		~Bureaucrat();

		// getters
		const std::string	getName() const;
		short int			getGrade() const;

		// member functions
		void	gradeIncrement();
		void	gradeDecrement();
		
		void	signForm(class AForm& cls);
		void	executeForm(const class AForm& cls) const;


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


std::ostream& operator<<(std::ostream& out, const Bureaucrat& cls);
