#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("Yahya"), grade(75) {}

Bureaucrat::Bureaucrat(Bureaucrat &val): name(val.name), grade(val.grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &val)
{
		if (&val != this)
		{
				name = val.name;
				grade = val.grade;
		}

		return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() { return name; }
short int	Bureaucrat::getGrade() { return grade; }


void		Bureaucrat::setName(std::string n) { name = n; }
void		Bureaucrat::setGrade(short int g) { grade = g; }

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

