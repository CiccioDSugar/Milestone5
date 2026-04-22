/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:34:23 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/02 14:34:23 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data    dataPtr;

    std::cout << "original: " << &dataPtr << std::endl;

    uintptr_t serialize = Serializer::serialize(&dataPtr);
    std::cout << "serialized: " << serialize << std::endl;
    Data* dese = Serializer::deserialize(serialize);
    std::cout << "deserialized: " << dese << std::endl;

    /* if (Serializer::deserialize(Serializer::serialize(dataPtr)) == dataPtr)
        std::cout << "Test ok." << std::endl;
    else
        std::cout << "Test failed." << std::endl; */
}