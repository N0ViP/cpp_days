#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("Yahya"), grade(75) {}

Bureaucrat::Bureaucrat(const std::string s): name(s), grade(75){}

Bureaucrat::Bureaucrat(Bureaucrat &val): name(val.name), grade(val.grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &val)
{
		if (&val != this)
		{
				grade = val.grade;
		}

		return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() { return name; }
short int	Bureaucrat::getGrade() { return grade; }

void		Bureaucrat::gradeIncrement()
{
		(grade > 1) ? grade-- : throw GradeTooHighException();
}

void		Bureaucrat::gradeDecrement()
{
		(grade < 150) ? grade++ : throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& cls)
{
		out << cls.getName()
				<< ", bureaucrat grade "
				<< cls.getGrade()
				<< std::endl;
		return out;
}

//inner class

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
		return "Failed to increment the grade: grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
		return "Failed to decrement the grade: grade is too low";
}
