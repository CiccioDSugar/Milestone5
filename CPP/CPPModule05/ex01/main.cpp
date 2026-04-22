/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:48:49 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/16 14:50:19 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int  main()
{
    std::cout << "Creating three Bureaucrats . . . " << std::endl << std::endl;
    Bureaucrat Berlusca("Berlusca", 1);
    Bureaucrat Giorgina("Giorgina", 75);
    Bureaucrat Matteuccio("Matteuccio", 150);
    
    std::cout << "Try to modify the grade of the magic trio " << std::endl << std::endl;
    try
    {
        Berlusca.gradeIncrement(1);
        Giorgina.gradeIncrement(50);
        Matteuccio.gradeDecrement(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Now let them 'works' " << std::endl << std::endl;
    Form form1("form1", false, 0, 1);
    Form form2("form2", false, 25, 1);
    Form form3("form3", false, 25, 1);
    try
    {
        form1.beSigned(Berlusca);
        form2.beSigned(Giorgina);
        form3.beSigned(Matteuccio);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}