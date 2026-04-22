/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:24:48 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/21 20:03:55 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 2)
        {
            std::cout << RPN_calculator(av[1]) << std::endl;
            return 0;
        }
        std::cerr << "Bad input." << std::endl;
        return 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}