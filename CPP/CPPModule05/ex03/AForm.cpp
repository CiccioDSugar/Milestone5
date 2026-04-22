/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:31:06 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/19 16:58:37 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*-----------------------------------EXCEPTION CLASS-----------------------------------*/

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade of this Bureaucrat is too high to sign this Form!\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade of this Bureaucrat is too low to sign this Form!\n";
}

const char* AForm::GradeToExecuteTooLowException::what() const throw()
{
    return "The grade of this Bureaucrat is too low to execute this Form!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "A Form must be already signed for being executed!";
}

/*-----------------------------------FORM CLASS-----------------------------------*/

/*----------------------------Constructors----------------------------*/

AForm::AForm() : name("JustCreatedForm"), gradeToSign(0), gradeToExecute(0), isSigned(false)
{
    std::cout << "Default constructor for a Form was called." << std::endl << std::endl;
}

AForm::AForm(AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
    std::cout << "Copy constructor for a Form was called." << std::endl << std::endl;
}

AForm::AForm(const std::string name, bool Signed, const int toSign, const int toExecute) : name(name), gradeToSign(toSign), gradeToExecute(toExecute), isSigned(Signed)
{
    std::cout << "Init constructor for a Form was called" << std::endl << std::endl;
}

/*----------------------------Operator overloads----------------------------*/

AForm&    AForm::operator=(AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		std::cout << "The rest of the variables is const and cannot be modified" << std::endl << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, AForm& form)
{
	os << form.getName() << " Form:" << std::endl << "Signed:" << form.getIsSigned() << std::endl 
    << "Grade to sign it is:" << form.getGradeToSign() << std::endl << 
    "Grade to execute it is:"<< form.getGradeToExecute() << std::endl << std::endl;
	return os;
}

/*----------------------------Member----------------------------*/

void    AForm::beSigned(Bureaucrat const &bureaucrat)
{
    std::cout << bureaucrat.getName() << " is trying to sign the form " << this->name << ". The grade required for signing it is: " << this->gradeToSign << std::endl
    << "The grade of the bureaucrat is: " << bureaucrat.getGrade() << std::endl << std::endl;
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
    std::cout << "The form " << this->name << " was successfully signed by " << bureaucrat.getName() << std::endl << std::endl;
}

/*----------------------------Destructor----------------------------*/

AForm::~AForm()
{
    std::cout << "Destructor for a Form was called" << std::endl << std::endl;
}

/*----------------------------GETTERS----------------------------*/

std::string AForm::getName()   const
{
    return this->name;
}

bool        AForm::getIsSigned() const
{
    return  this->isSigned;
}

int         AForm::getGradeToSign()  const
{
    return this->gradeToSign;
}

int         AForm::getGradeToExecute()   const
{
    return this->gradeToExecute;
}

