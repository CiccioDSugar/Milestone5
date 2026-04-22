/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:32:45 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/20 21:24:08 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() 
{
    std::cout << std::endl << std::endl << "--------------------Creation of a PresidentialPardonForm by an Intern--------------------" << std::endl << std::endl;
    Intern someRandomIntern;
    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "AGuy");
    delete ppf;
    
    std::cout << "--------------------Creation of a RobotomyRequestForm by an Intern--------------------" << std::endl << std::endl;
    Intern otherRandomIntern;
    AForm* rrf;
    rrf = otherRandomIntern.makeForm("robotomy request", "Me");
    delete rrf;
    
    std::cout << "--------------------Creation of a ShrubberyCreationForm by an Intern--------------------" << std::endl << std::endl;
    Intern anotherRandomIntern;
    AForm* scf;
    scf = anotherRandomIntern.makeForm("shrubbery creation", "You");
    delete scf;
    
    std::cout << "--------------------Creation of a Form with an invalid name by an Intern--------------------" << std::endl << std::endl;
    Intern inableRandomIntern;
    AForm* inf;
    inf = inableRandomIntern.makeForm("potential form", "Potential target");
    delete inf;

    std::cout << "--------------------INTERN DESTRUCTORS CALLS--------------------" << std::endl << std::endl;

    
}