/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:43:09 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 12:03:20 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", false,  72, 45)
{
    this->target = target;
    std::cout << "Default constructor for a RobotomyRequestForm was called." << std::endl << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : target(other.target)
{
    std::cout << "Copy constructor for a RobotomyRequestForm was called." << std::endl << std::endl;
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor for a RobotomyRequestForm was called." << std::endl << std::endl;
}
            
void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw(AForm::FormNotSignedException());
    if (executor.getGrade() > getGradeToExecute())
        throw(AForm::GradeToExecuteTooLowException());
        
    std::cout << "BZZZZ . .  BZZZZ . . *drilling noise* BZZZZ . . BZZZZ . . " << std::endl << std::endl;
    
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << "bzzz . . bzzz . . " << target << "was *bzz* successfully ro*bzz*botomized . . " << std::endl << std::endl;
    else
        std::cout << "bzz . . Robotomy of " << target << " bzzz failed. bzbzbz . ." << std::endl << std::endl;
    
    std::cout << "BzBzBzBzBzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz........." << std::endl << std::endl;
}