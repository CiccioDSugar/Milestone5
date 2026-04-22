/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:28:23 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/25 16:53:42 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>
#include <cctype>

enum    e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    INVALIDINPUT
};

class ScalarConverter
{
    public:
    static void     convert(const std::string& literal);
    
    private:
/*-----------------OCF-----------------*/
                    ScalarConverter();
                    ScalarConverter(ScalarConverter &other);
ScalarConverter&    operator=(ScalarConverter &other);
                    ~ScalarConverter();
};
/*-----------------Functions----------------*/

e_type  find_type(const std::string &str);

void	    printAll(const std::string &str, e_type type);


#endif