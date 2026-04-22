/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:32:45 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 12:52:59 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() 
{
    try {
        std::cout << "----------------------------Creating some Bureaucrat----------------------------" << std::endl << std::endl;
        Bureaucrat Berlusca("Berlusca", 1);
        Bureaucrat Giorgina("Giorgina", 50);
        Bureaucrat Matteuccio("Matteuccio", 150);
        
        std::cout << Berlusca << std::endl;
        std::cout << Giorgina << std::endl; 
        std::cout << Matteuccio << std::endl;
        
        std::cout << "----------------------------Creating some Forms----------------------------" << std::endl << std::endl;
        ShrubberyCreationForm Shrub("Arcore's villa");
        RobotomyRequestForm Robot("IlTrota");
        PresidentialPardonForm Pardon("Arthur Dent");
        
        std::cout << Shrub << std::endl;
        std::cout << Robot << std::endl;
        std::cout << Pardon << std::endl;
        
        std::cout << "----------------------------Testing ShrubberyCreationForm----------------------------" << std::endl << std::endl;
        Berlusca.signForm(Shrub);
        Berlusca.executeForm(Shrub);
        Matteuccio.executeForm(Shrub);
        
        std::cout << "----------------------------Testing RobotomyRequestForm----------------------------" << std::endl << std::endl;
        Giorgina.signForm(Robot);
        Giorgina.executeForm(Robot);
        Berlusca.executeForm(Robot);
        
        std::cout << "----------------------------Testing PresidentialPardonForm----------------------------" << std::endl << std::endl;
        Berlusca.signForm(Pardon);
        Berlusca.executeForm(Pardon);
        Giorgina.executeForm(Pardon);
        
        std::cout << "----------------------------Testing Unsigned Forms----------------------------" << std::endl << std::endl;
        PresidentialPardonForm unsigned_form("Nobody");
        Berlusca.executeForm(unsigned_form);
        
    } catch (std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    return 0;
}