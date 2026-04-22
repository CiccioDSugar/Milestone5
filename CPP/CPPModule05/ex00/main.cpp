/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:11:24 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 14:45:00 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--------------------------Constructors tests--------------------------" << std::endl << std::endl;
    Bureaucrat Berlusca("Berlusca", 1);
    std::cout << Berlusca << std::endl << std::endl;
    Bureaucrat Giorgina("Giorgina", 100);
    std::cout << Giorgina << std::endl << std::endl;
    Bureaucrat IlTrota(Berlusca);
    std::cout << "--------------------------Exceptions tests--------------------------" << std::endl << std::endl;
    try
    {
        Berlusca.gradeIncrement(0);
        Berlusca.gradeIncrement(1);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
      try
    {
        Giorgina.gradeDecrement(1);
        Giorgina.gradeDecrement(50);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}