/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:25:46 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/18 16:57:42 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
    private:
        
    public:
                    Intern();
                    Intern(Intern &other);
        Intern&     operator=(Intern &other);     
        AForm       *makeForm(std::string formName, std::string formTarget);
                    ~Intern();
    };

#endif