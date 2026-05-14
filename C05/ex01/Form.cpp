#include "Form.hpp"
#include <iostream>

Form::Form() : name("form"), sign(false), gradeToSign(75), gradeToExecute(75) {}

Form::Form(const std::string name, const short int gradeToSign, const short int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
		if (gradeToSign < 1 || gradeToExecute < 1)
				throw Form::GradeTooHighException();
		else if (gradeToSign > 150 || gradeToExecute > 150)
				throw Form::GradeTooLowException();
}

Form::Form(const Form& cls) : name(cls.name), sign(cls.sign), gradeToSign(cls.gradeToSign), gradeToExecute(cls.gradeToExecute) {}

Form& Form::operator=(const Form& cls)
{
	if (this != &cls)
	{
		sign = cls.sign;
	}
	return *this;
}

Form::~Form() {}


std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return sign; }
short int Form::getGradeToSign() const { return gradeToSign; }
short int Form::getGradeToExecute() const { return gradeToExecute; }


void Form::beSigned(const Bureaucrat& cls)
{
	if (cls.getGrade() > gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		sign = true;
	}
}

std::ostream& operator<<(std::ostream& out, const Form& cls)
{
	out << "Form name: " << cls.getName() << std::endl;
	out << "Grade required to sign: " << cls.getGradeToSign() << std::endl;
	out << "Grade required to execute: " << cls.getGradeToExecute() << std::endl;
	out << "Is the form signed? " << (cls.getIsSigned() ? "Yes" : "No") << std::endl;
	return out;
}



const char* Form::GradeTooHighException::what() const throw()
{
		return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
		return "grade is too low";
}
