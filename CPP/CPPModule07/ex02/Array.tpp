/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:06:41 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/06 17:19:09 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->array = new T[0];
    this->_size = 0;
    std::cout << "Default constructor for an Array was called." << std::endl << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->_size = n;
    this-> array = new T[n];
    std::cout << "Int init constructor for an Array was called." << std::endl << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other)
{
    this->_size = other._size;
    if (_size == 0)
        this->array = NULL;
    else
    {
        this->array = new T[_size];
        for(unsigned int i = 0; i < _size; i++)
        {
            this->array[i] = other.array[i];
        }
    }
    std::cout << "Copy constructor for an Array was called" << std::endl << std::endl;
    
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] array;
        this->_size = other._size;
        this->array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            this->array[i] = other.array[i];
    }
    return *this;
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
    if (!_size)
        return 0;
    if (index >= this->size() || index < 0)
    {
        throw (OutOfRange());    
    }
    return array[index];
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
    if (index >= this->size() || index < 0)
    {
        throw(OutOfRange());
    }
    return array[index];
}


template <typename T>
unsigned int    Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
Array<T>::~Array()
{
    delete [] array;
    std::cout << "Destructor for an Array was called." << std::endl <<std::endl;
}
