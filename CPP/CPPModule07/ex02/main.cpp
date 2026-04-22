/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:44:41 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/06 17:21:30 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    // Array vuoto
    try
    {
        
        Array<int> emptyArray;
    
        // Array con 5 elementi
        Array<int> arrayWith5(5);
    
        // Copia
        Array<int> copy(arrayWith5);
    
        std::cout << "Size vuoto: " << emptyArray.size() << std::endl;
        // Posso usarli subito
        std::cout << "Size con 5: " << arrayWith5.size() << std::endl;
        std::cout << "Size copia con 5: " << copy.size() << std::endl;
        std::cout << "Filling arrayWith5 with: 0, 1, 2, 3, 4." << std::endl;
        for (unsigned int i = 0; i < arrayWith5.size(); i++)
            arrayWith5[i] = i;
        std::cout << "Cloning and printing copy elements." << std::endl;
        for (unsigned int i = 0; i < copy.size(); i++)
        {
            copy[i] = arrayWith5[i];
            std::cout << copy[i] << std::endl;
        }
    
        std::cout << "test" << std::endl;
        
        int* a = new int();
            std::cout << *a << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
