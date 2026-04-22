/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:11:15 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 14:45:26 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*-----------------------------------EXCEPTION CLASS-----------------------------------*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade of this Bureaucrat is too high! It must be between 1 and 150!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade of this Bureaucrat is too low! It must be between 1 and 150!\n";
}

/*-----------------------------------BUREAUCRAT-----------------------------------*/

/*----------------------------Constructors----------------------------*/
Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Default constructor for a Bureaucrat called" << std::endl << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name), grade(other.grade) 
{
	std::cout << "Copy constructor for a Bureaucrat called" << std::endl << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if(grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << "Init constructor for a Bureaucrat called" << std::endl << std::endl;
}

/*----------------------------Operator overloads----------------------------*/

Bureaucrat&    Bureaucrat::operator=(Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
		std::cout << "'name' is a const variable and cannot be modified" << std::endl << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl << std::endl;
	return os;
}

void    Bureaucrat::gradeIncrement(int n)
{
	std::cout << "Trying to increment the grade of a bureaucrat from " << this->grade << " to " << this->grade - n << std::endl << std::endl;
	if ((this->grade - n) < 1 )
		throw Bureaucrat::GradeTooHighException();
	this->grade-= n;
	std::cout << "Grade was succesfully incremented to " << this->grade << std::endl << std::endl;
}

void    Bureaucrat::gradeDecrement(int n)
{
	std::cout << "Trying to decrement the grade of a bureaucrat from " << this->grade << " to " << this->grade + n << std::endl << std::endl;
	if ((this->grade + n) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += n;
	std::cout << "Grade was succesfully decremented to " << this->grade << std::endl << std::endl;
}

/*----------------------------Getters----------------------------*/

const std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

Bureaucrat::~Bureaucrat()
{
    
}