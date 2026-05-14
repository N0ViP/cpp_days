#pragma once

#include <stdexcept>
#include "Bureaucrat.hpp"
#include <iostream>

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const short int		gradeToSign;
		const short int		gradeToExecute;

		
		
		public:
		AForm();
		AForm(const std::string name, const short int gradeToSign, const short int gradeToExecute);
		AForm(const AForm& cls);
		AForm& operator=(const AForm& cls);
		~AForm();
		
		// getters
		std::string	getName() const;
		bool		getIsSigned() const;
		short int	getGradeToSign() const;
		short int	getGradeToExecute() const;
		
		
		virtual void	execute(const class Bureaucrat& executor) const = 0;
		
		void beSigned(const class Bureaucrat& cls);

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

std::ostream& operator<<(std::ostream& out, const AForm& cls);