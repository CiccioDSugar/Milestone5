/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:31:08 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/17 12:34:12 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   name;
    const int           gradeToSign;
    const int           gradeToExecute;
          bool          isSigned;
    public:
                    AForm();
                    AForm(AForm &other);
            		AForm(const std::string name, bool Signed, const int toSign, const int toExecute);
    AForm&          operator=(AForm &other);    
    void            beSigned(Bureaucrat const &bureaucrat);
    virtual	void	execute(Bureaucrat const & executor) const = 0;
    virtual         ~AForm();

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

    class GradeToExecuteTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream &os, AForm& form);

#endif