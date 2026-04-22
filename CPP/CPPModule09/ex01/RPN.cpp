/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:24:43 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/11/19 16:04:13 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int    RPN_calculator(std::string str)
{
    std::istringstream  iss(str);
    std::string         token;
    std::stack<int>     stack;
    int                 result = -2147483648;
    int                 i = 0;

    while (iss >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
        {
            int nbr = token[0] - 48;
            stack.push(nbr);
        }
        else if ( token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
            if (stack.size() < 2)
            {
                if (i == 0)
                    throw (std::runtime_error("Error: too few elements in the stack for making an operation"));
                else
                    throw std::runtime_error("Error: something went wrong and less then 2 numbers remained in the stack.");
            }

            int     nbr2 = stack.top();
            stack.pop();
            int     nbr1 = stack.top();
            stack.pop();

            if (token[0] == '+')
                result = nbr1 + nbr2;
            if (token[0] == '-')
                result = nbr1 - nbr2;
            if (token[0] == '*')
                result = nbr1 * nbr2;
            if (token[0] == '/')
            {
                if (nbr2 == 0)
                {
                    std::cerr << "Error: Division by 0 is not possible." << std::endl;
                    return 0;
                }
                result = nbr1 / nbr2;
            }
            stack.push(result);
        }
        else
            throw std::runtime_error("Error: invalid token found in the line.");
    }
    return result;
}