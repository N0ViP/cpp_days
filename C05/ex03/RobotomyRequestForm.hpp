#pragma once

#include "AForm.hpp"
#include <fstream>


class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& cls);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& cls);
        ~RobotomyRequestForm();

        virtual void execute(const Bureaucrat& executor) const;
};