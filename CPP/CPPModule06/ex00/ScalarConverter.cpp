/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:28:20 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/26 19:24:04 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

/*-----------------------------------ORTHODOX CANONICAL FORM-----------------------------------*/
ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor for a ScalarConverter was called." << std::endl << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter &other)
{
    *this = other;
    std::cout << "Copy constructor for a ScalarConverter was called." << std::endl << std::endl;
}

ScalarConverter&    ScalarConverter::operator=(ScalarConverter &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor for a ScalarConverter was called" << std::endl << std::endl;
}

/*-----------------------------------HELPER-----------------------------------*/

bool is_valid_float(const std::string str)
{
	int size = str.size();
	int i = 0;
    while (i < size)
    {
    	if (str[i] == '.' || str[i] == 'f' || str[i] == '-' || str[i] == '+')
			i++;
		if (i >= size)
			break;
    	if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
		{
        	return false;
		}
		i++;
    }
	if (std::count(str.begin(), str.end(), 'f') == 1 && std::count(str.begin(), str.end(), '.') == 1)
		return true;
	else
		return false;
}

bool    is_valid_double(const std::string &str)
{
	int size = str.size();

	for (int i = 0; i < size; i++)
    {
    	if (str[i] == '.' || str[i] == '-' || str[i] == '+')
        	i++;
    	if (!isdigit(str[i]))
        	return false;
    }
	if (!std::count(str.begin(), str.end(), 'f') && std::count(str.begin(), str.end(), '.') == 1 )
    	return true;
	else
		return false;
}

bool is_int(const std::string &str)
{
	int size = str.size();
	
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

e_type  find_type(const std::string &str)
{
    if (str.empty())
        return INVALIDINPUT;
    else if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
        return CHAR;
	else if (is_int(str))
		return INT;
    else if ( is_valid_float(str))
        return FLOAT;
    else if (str[str.size()] != 'f' && is_valid_double(str))
		return DOUBLE;
	else if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "nan" || str == "nanf")
		return SPECIAL;
	else
		return INVALIDINPUT;
}

char    str_to_char(const std::string &str)
{
	return str[1];
}

int     str_to_int(const std::string &str)
{
	return atoi(str.c_str());
}

float   str_to_float(const std::string &str)
{
	std::string noF;
	noF = str.substr(0, (str.size() - 1));
	return atof(noF.c_str());
}

double  str_to_double(const std::string &str)
{
	return atof(str.c_str());
}

bool	ioor(std::string str)
{
	long long	actual = atoll(str.c_str());

	if (actual > 2147483647 || actual < -2147483648)
		return true;
	return false;

}

void	ScalarConverter::convert(const std::string &str)
{
	char 		c;
	int 		i;
	float 		f;
	double 		d;
	long long	e = 0;

	(void)e;
	
	e_type type = find_type(str);
	
	if (type == INT && ioor(str))
	{
		type = INVALIDINPUT;
	}
	switch(type)
	{
		case CHAR:
		std::cout << "Type found is a CHAR, now it will be casted in the other types:" << std::endl << std::endl;
		c = str_to_char(str);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		break;
		case INT:
		std::cout << "Type found is a INT, now it will be casted in the other types:" << std::endl << std::endl;
		i = str_to_int(str);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		break;
		case FLOAT:
		std::cout << "Type found is a FLOAT, now it will be casted in the other types:" << std::endl << std::endl;
		f = str_to_float(str);
		c = static_cast<char>(f);
		e = static_cast<long long>(atoll(str.c_str()));
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		break;
		case DOUBLE:
		std::cout << "Type found is a DOUBLE, now it will be casted in the other types:" << std::endl << std::endl;
		d = str_to_double(str);
		c = static_cast<char>(d);
		e = static_cast<long long>(atoll(str.c_str()));
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		break;
		case SPECIAL:
		std::cout << "Type found is a SPECIAL, now it will be casted in the other types:" << std::endl << std::endl;
			if (str == "nan")
			{
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl
				<< "float: nanf" << std::endl << "double: nan" << std::endl;
			}
			else if (str == "nanf")
			{
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl
				<< "float: nanf" << std::endl << "double: nan" << std::endl;
			}
			else if (str == "-inf")
			{
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl
				<< "float: -inff" << std::endl << "double: -inf" << std::endl;
			}
			else if (str == "+inf")
			{
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl
				<< "float: +inff" << std::endl << "double: +inf" << std::endl;
			}
			else if (str == "-inff")
			{
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl
				<< "float: -inff" << std::endl << "double: -inf" << std::endl;
			}
			else if (str == "+inff")
			{
				std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl
				<< "float: +inff" << std::endl << "double: +inf" << std::endl;
			}
			return ;
		case INVALIDINPUT:
		{
			std::cout << "Program individuated an INVALIDINPUT error" << std::endl << std::endl;
			return ;
		}
		break;
		}
	if (d < 0 || d > 127)
	std::cout << "char: impossible" << std::endl;
	else
	{
		if (std::isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
		else
		std::cout << "char: Non displayable" << std::endl;
	}
	if (e > INT_MAX || e < INT_MIN)
        std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	if (static_cast<long long>(f) < -std::numeric_limits<float>::max() || static_cast<long long>(f) > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(2) << "float: " << f << "f" << std::endl;
    
	if (static_cast<long long>(d) < -std::numeric_limits<double>::max() || static_cast<long long>(d) > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(2) << "double: " << d << std::endl;
}




