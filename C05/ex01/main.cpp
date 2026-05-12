#include "Bureaucrat.hpp"


int main(void)
{

		Bureaucrat bureau1;
		Bureaucrat bureau2(bureau1);
		Bureaucrat bureau3;
		Bureaucrat::GradeTooHighException exctoohigh;
		Bureaucrat::GradeTooLowException exctoolow;
		
		bureau1.setName("eve");
		bureau1.setGrade(5);

		bureau2.setGrade(145);
		
		bureau3 = bureau1;


		std::cout << "=========================================" << std::endl;
		
		std::cout << bureau1;
		std::cout << bureau2;
		std::cout << bureau3;

		std::cout << "=========================================" << std::endl;

		try
		{
				while (true)
				{
						std::cout << bureau1;
						bureau1.gradeIncrement();
				}
		}
		catch (std::exception & e)
		{
				std::cout << e.what() << std::endl;
		}

		std::cout << "=========================================" << std::endl;

		try
		{
				while (true)
				{
						std::cout << bureau2;
						bureau2.gradeDecrement();
				}
		}
		catch (std::exception & e)
		{
				std::cout << e.what() << std::endl;
		}

		std::cout << "=========================================" << std::endl;

}
