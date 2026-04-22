/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:11:20 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 14:41:14 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;
public:
                        Bureaucrat();
                        Bureaucrat(Bureaucrat &other);
                        Bureaucrat(std::string name, int grade);
    Bureaucrat&         operator=(Bureaucrat &other);
    const std::string   getName() const;
    int                 getGrade() const;
    void                gradeIncrement(int n);
    void                gradeDecrement(int n);
                        ~Bureaucrat();
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream &os, Bureaucrat& bureaucrat);

#endif