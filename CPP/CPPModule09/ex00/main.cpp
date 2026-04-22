/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:48:36 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/11/21 19:52:51 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 2)
    {
        std::string inputfile = av[1];
        if ( inputfile == "input.txt" )
        {
            BitcoinExchange btc;
            btc.process_inFile(av[1]);
            return 0;
        }
    }
    std::cerr << "Expected 'input.txt' as input file." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}