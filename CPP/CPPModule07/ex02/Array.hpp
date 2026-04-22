/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:44:28 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/03 18:47:22 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T   *array;
    unsigned int _size;
public:
                Array();
                Array(const Array &other);
    		    Array(unsigned int n); //create array of n elements initialized by default
    Array&	    operator=(const Array& other);
    T&	        operator[](unsigned int index);
    const T&	operator[](unsigned int index) const;
        	    ~Array();

    unsigned int	size() const;
    
    class OutOfRange : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

template <typename T>
const char* Array<T>::OutOfRange::what() const throw()
{
    return "Index out of range";
}

#include "Array.tpp"

#endif