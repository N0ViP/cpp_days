#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	Bureaucrat bureau1;
	Form form;
	Form form1("fomr1", 150, 150);
	Form form2("form2", 1, 1);

	std::cout << bureau1;
	std::cout << "===================================" << std::endl;
	std::cout << form;
	std::cout << "===================================" << std::endl;
	std::cout << form1;
	std::cout << "===================================" << std::endl;
	std::cout << form2;

	std::cout << "===================================" << std::endl;

	try
	{
		Form form3("form3", 0, 75);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "===================================" << std::endl;

	bureau1.signForm(form);
	bureau1.signForm(form1);
	bureau1.signForm(form2);

	std::cout << "===================================" << std::endl;

}
