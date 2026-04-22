/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:36 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/19 17:04:12 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Default constructor fo an Intern was called" << std::endl << std::endl;
}

Intern::Intern(Intern &other)
{
    *this = other;
    std::cout << "Copy constructor for an Intern was called" << std::endl;
}

Intern&     Intern::operator=(Intern &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

AForm*   Intern::makeForm(std::string formName, std::string formTarget)
{
    AForm *newForm;
    int formIndex = -1;
    std::string choises[3] = {"presidential pardon","robotomy request" ,"shrubbery creation"};

    for (int i = 0; i < 3 ; i++)
    {
        if (choises[i] == formName)
        {
            formIndex = i;
            break ;
        }

    }
    switch(formIndex)
    {
        case 0:
            newForm = new PresidentialPardonForm(formTarget);
            std::cout << "Intern is creating a " << formName << " form." << std::endl << std::endl;
            return newForm;
        case 1:
            newForm = new RobotomyRequestForm(formTarget);
            std::cout << "Intern is creating a " << formName << " form." << std::endl << std::endl;
            return newForm;
        case 2:
            newForm = new ShrubberyCreationForm(formTarget);
            std::cout << "Intern is creating a " << formName << " form." << std::endl << std::endl;
            return newForm;
        default:
            std::cout << "No matches found between form name and valid names for a form." << std::endl << std::endl;
            return NULL;
    }
}

Intern::~Intern()
{
    std::cout << "Destructor for an Intern was called" << std::endl << std::endl;
}