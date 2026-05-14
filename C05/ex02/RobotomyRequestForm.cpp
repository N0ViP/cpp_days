#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cls) : AForm(cls), target(cls.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cls)
{
    if (this != &cls)
    {
        AForm::operator=(cls);
        target = cls.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Some bullshi... " << target << " has been robotomized successfully 50% of the time." << std::endl;
}