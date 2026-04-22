/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:19:24 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 12:53:07 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <exception>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
            					ShrubberyCreationForm(const std::string &target);
								ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm&		operator=(const ShrubberyCreationForm &other);
								~ShrubberyCreationForm();
	
	void		execute(Bureaucrat const & executor) const;
};

#endif