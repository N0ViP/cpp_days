#include "Form.hpp"
#include <iostream>

AForm::AForm() : name("form"), sign(false), gradeToSign(75), gradeToExecute(75) {}

AForm::AForm(const std::string name, const short int gradeToSign, const short int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
		if (gradeToSign < 1 || gradeToExecute < 1)
				throw AForm::GradeTooHighException();
		else if (gradeToSign > 150 || gradeToExecute > 150)
				throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& cls) : name(cls.name), sign(cls.sign), gradeToSign(cls.gradeToSign), gradeToExecute(cls.gradeToExecute) {}

AForm& AForm::operator=(const AForm& cls)
{
	if (this != &cls)
	{
		sign = cls.sign;
	}
	return *this;
}

AForm::~AForm() {}


std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return sign; }
short int AForm::getGradeToSign() const { return gradeToSign; }
short int AForm::getGradeToExecute() const { return gradeToExecute; }


void AForm::beSigned(const Bureaucrat& cls)
{
	if (cls.getGrade() > gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		sign = true;
	}
}

std::ostream& operator<<(std::ostream& out, const AForm& cls)
{
	out << "Form name: " << cls.getName() << std::endl;
	out << "Grade required to sign: " << cls.getGradeToSign() << std::endl;
	out << "Grade required to execute: " << cls.getGradeToExecute() << std::endl;
	out << "Is the form signed? " << (cls.getIsSigned() ? "Yes" : "No") << std::endl;
	return out;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!sign)
	{
		throw std::runtime_error("Form is not signed");
	}
	else if (executor.getGrade() > gradeToExecute)
	{
		throw AForm::GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
		return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
		return "grade is too low";
}
