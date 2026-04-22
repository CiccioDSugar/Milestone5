/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:34:35 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/10 17:13:32 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> commonContainer;
    std::cout << std::endl << "We have a vector with four integers inside: 1, 34, 42 and 24." << std::endl << std::endl; 
    commonContainer.push_back(1);
    commonContainer.push_back(34);
    commonContainer.push_back(42);
    commonContainer.push_back(24);

    std::vector<int>::const_iterator eF;
    
    std::cout << "Now we are tasting easyfind() with our container and the integer '24'. It should find a match." << std::endl << std::endl;
    eF = easyfind(commonContainer, 24);
    if (eF != commonContainer.end())
        std::cout << "Match was found: " << *eF << std::endl << std::endl;
    else
        std::cout << "No match was found." << std::endl << std::endl;
    std::cout << "Now try with the integer '2'. It should NOT find a match." << std::endl << std::endl;
    eF = easyfind(commonContainer, 2);
    if (eF != commonContainer.end())
        std::cout << "Match was found: " << *eF << std::endl << std::endl;
    else
        std::cout << "No match was found." << std::endl << std::endl;
    return 0;
}