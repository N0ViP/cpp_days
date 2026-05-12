#include "Bureaucrat.hpp"


int main(void)
{

		Bureaucrat bureau1("Eve");
		Bureaucrat bureau2("Adam");
		Bureaucrat bureau3(bureau1);
		Bureaucrat bureau4;

		std::cout << "=========================================" << std::endl;
		
		std::cout << bureau1;
		std::cout << bureau2;
		std::cout << bureau3;
		std::cout << bureau4;


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
