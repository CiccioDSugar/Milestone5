/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:43:06 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 12:37:05 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", false,  145, 137)
{
    this->target = target;
    std::cout << "Default constructor for a ShrubberyCreationForm was called." << std::endl << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : target(other.target)
{
    std::cout << "Copy constructor for a ShrubberyCreationForm was called." << std::endl << std::endl;
}

ShrubberyCreationForm&    ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor for a ShrubberyCreationForm was called." << std::endl << std::endl;
}
            
void    ShrubberyCreationForm::execute( const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeToExecuteTooLowException();
    std::string filename = target + "_Shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
        throw(std::runtime_error("Shrubbery file couldn't be created"));
    file << "       /\\       " << std::endl;
    file << "      /  \\      " << std::endl; 
    file << "     /    \\     " << std::endl;
    file << "    /______\\    " << std::endl;
    file << "       ||        " << std::endl;
    file << "                 " << std::endl;
    file << "       /\\       " << std::endl;
    file << "      /  \\      " << std::endl;
    file << "     /____\\     " << std::endl;
    file << "       ||        " << std::endl;
    
    file.close();
}