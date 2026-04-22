/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:16:22 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/25 17:44:54 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Constructor for a Serializer was called." << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Copy constructor for a Serializer was called." << std::endl;
    *this = other;
}

Serializer& Serializer::operator=(const Serializer &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Destructor for a Serializer was called." << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t intPtr;
    
    intPtr = reinterpret_cast<uintptr_t>(ptr);
    
    return intPtr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* dataPtr;
    
    dataPtr = reinterpret_cast<Data*>(raw);
    
    return dataPtr;
}