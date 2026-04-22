/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:31:06 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 12:34:45 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*-----------------------------------EXCEPTION CLASS-----------------------------------*/

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade of this Bureaucrat is too high to sign this Form!\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade of this Bureaucrat is too low to sign this Form!\n";
}

/*-----------------------------------FORM CLASS-----------------------------------*/

/*----------------------------Constructors----------------------------*/

Form::Form() : name("JustCreatedForm"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "Default constructor for a Form was called." << std::endl << std::endl;
}

Form::Form(Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Copy constructor for a Form was called." << std::endl << std::endl;
}

Form::Form(const std::string name, bool Signed, const int toSign, const int toExecute) : name(name), isSigned(Signed), gradeToSign(toSign), gradeToExecute(toExecute)
{
    std::cout << "Init constructor for a Form was called" << std::endl << std::endl;
}

/*----------------------------Operator overloads----------------------------*/

Form&    Form::operator=(Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		std::cout << "The rest of the variables is const and cannot be modified" << std::endl << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, Form& form)
{
	os << form.getName() << " Form:" << std::endl << "Signed:" << form.getIsSigned() << std::endl 
    << "Grade to sign it is:" << form.getGradeToSign() << std::endl << 
    "Grade to execute it is:"<< form.getGradeToExecute() << std::endl << std::endl;
	return os;
}

/*----------------------------Member----------------------------*/

void    Form::beSigned(Bureaucrat const &bureaucrat)
{
    std::cout << bureaucrat.getName() << " is trying to sign the form " << this->name << ". The grade required for signing it is: " << this->gradeToSign << std::endl
    << "The grade of the bureaucrat is: " << bureaucrat.getGrade() << std::endl << std::endl;
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
    std::cout << "The form " << this->name << " was successfully signed by " << bureaucrat.getName() << std::endl << std::endl;
}

/*----------------------------Destructor----------------------------*/

Form::~Form()
{
    std::cout << "Destructor for a Form was called" << std::endl << std::endl;
}

/*----------------------------GETTERS----------------------------*/

std::string Form::getName()   const
{
    return this->name;
}

bool        Form::getIsSigned() const
{
    return  this->isSigned;
}

int         Form::getGradeToSign()  const
{
    return this->gradeToSign;
}

int         Form::getGradeToExecute()   const
{
    return this->gradeToExecute;
}

