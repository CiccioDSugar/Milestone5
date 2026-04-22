/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:48:54 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/10 16:16:58 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    Span ssp = Span(7);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "The shortest span is: " << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << "The longest span is: " << std::endl;
        std::cout << sp.longestSpan() << std::endl; 
        unsigned int arr[] = {1, 2, 3, 4, 5};
        std::vector<unsigned int> vector2(arr, arr + 5);
        std::vector<unsigned int>::const_iterator start = vector2.begin();
        std::vector<unsigned int>::const_iterator end = vector2.end();
        std::cout << "Now we are filling the array with a range of iterator from 1 to 5, This storage has capacity 7." << std::endl;
        ssp.addMultipleNumber(start, end);
        std::cout << "Storage vector after addMultipleNumber() : " << std::endl;
        for (unsigned int i = 0; i < ssp.get_maxSize(); i++)
        {
            std::cout << ssp.getStorage()[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    
    return 0;
}