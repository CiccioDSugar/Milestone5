/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:19:17 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 14:47:28 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <exception>

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
                            PresidentialPardonForm(const std::string& target);
                            PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
                            ~PresidentialPardonForm();
            
    void    execute(Bureaucrat const & executor) const;
};

#endif