/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:31:08 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/17 12:33:38 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   name;
    bool                isSigned;
    const int           gradeToSign;
    const int           gradeToExecute;
public:
            Form();
            Form(Form &other);
            Form(const std::string name, bool Signed, const int toSign, const int toExecute);
    Form&   operator=(Form &other);    
    void    beSigned(Bureaucrat const &bureaucrat);
            ~Form();

/*---------------------GETTERS---------------------*/

   std::string getName()           const;
   bool        getIsSigned()       const;
   int         getGradeToSign()    const;
   int         getGradeToExecute() const;

/*---------------------EXCEPTIONS---------------------*/

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

std::ostream&   operator<<(std::ostream &os, Form& form);

#endif