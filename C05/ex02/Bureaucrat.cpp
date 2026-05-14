#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("Yahya"), grade(75) {}

Bureaucrat::Bureaucrat(const std::string s, const short int g): name(s), grade(g)
{
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (g > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &val): name(val.name), grade(val.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &val)
{
	if (&val != this)
	{
		grade = val.grade;
	}

	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const { return name; }
short int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::signForm(AForm& cls)
{
	try
	{
		cls.beSigned(*this);
		std::cout << name << " signed " << cls.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << name << " couldn't sign " << cls.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& cls) const
{
	try
	{
		cls.execute(*this);
		std::cout << name << " executed " << cls.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << name << " couldn't execute " << cls.getName() << " because " << e.what() << std::endl;
	}
}


void	Bureaucrat::gradeIncrement()
{
	(grade > 1) ? grade-- : throw GradeTooHighException();
}

void	Bureaucrat::gradeDecrement()
{
	(grade < 150) ? grade++ : throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& cls)
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
	return "The grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}
