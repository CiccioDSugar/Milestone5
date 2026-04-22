/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:16:19 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/24 16:11:10 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
private:
                Serializer();
                Serializer(const Serializer &other);
                Serializer& operator=(const Serializer &other);
                ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static  Data* deserialize(uintptr_t raw);
};

#endif