#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

	Bureaucrat	bureau1;
	Intern		intern1;
	AForm		*form1 = intern1.makeForm("PresidentialPardonForm", "target1");
	AForm		*form2 = intern1.makeForm("RobotomyRequestForm", "target2");
	AForm		*form3 = intern1.makeForm("ShrubberyCreationForm", "target3");

	std::cout << bureau1 << std::endl;
	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;
	
	std::cout << "===================================" << std::endl;

	bureau1.signForm(*form1);
	bureau1.signForm(*form2);
	bureau1.signForm(*form3);

	std::cout << "===================================" << std::endl;

	bureau1.executeForm(*form1);
	bureau1.executeForm(*form2);
	bureau1.executeForm(*form3);

	std::cout << "===================================" << std::endl;

	try
	{
		form1->execute(bureau1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "===================================" << std::endl;

	try
	{	
		form2->execute(bureau1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "===================================" << std::endl;
	try
	{
		form3->execute(bureau1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	delete form1;
	delete form2;
	delete form3;

	return 0;
}
