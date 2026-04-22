/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:43:13 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 14:39:25 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", false,  25, 5)
{
    this->target = target;
    std::cout << "Default constructor for a PresidentialPardonForm was called." << std::endl << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : target(other.target)
{
    std::cout << "Copy constructor for a PresidentialPardonForm was called." << std::endl << std::endl;
}

PresidentialPardonForm&    PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor for a PResidentialPardonForm was called." << std::endl << std::endl;
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw(AForm::GradeToExecuteTooLowException());
    std::cout << target << "has been pardoned by Zaphod Beeblebrox." << std::endl << std::endl;
}