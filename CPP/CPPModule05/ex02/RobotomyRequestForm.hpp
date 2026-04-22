/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:19:21 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 12:55:34 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <exception>

class RobotomyRequestForm :public AForm
{
private:
    std::string target;
public:
                                RobotomyRequestForm(const std::string& target);
                                RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm&        operator=(const RobotomyRequestForm& other);
                                ~RobotomyRequestForm();
    
    void    execute(Bureaucrat const & executor) const;
};

#endif