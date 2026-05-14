#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cls) : AForm(cls), target(cls.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cls)
{
    if (this != &cls)
    {
        AForm::operator=(cls);
        this->target = cls.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
