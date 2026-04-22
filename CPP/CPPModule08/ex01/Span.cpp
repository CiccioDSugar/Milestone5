/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:05:59 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/10 16:13:25 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    std::cout << "Default constructor for a Span was called." << std::endl;
}

Span::Span(unsigned int capacity)
{
    this->maxSize = capacity;
	this->storage.reserve(capacity);
    std::cout << "Init constructor for a Span was called." << std::endl;
}

Span::Span(const Span &other)
{
    this->storage = other.storage;
    this->maxSize = other.maxSize;
    std::cout << "Copy constructor for a Span was called." << std::endl;
}

const Span&   Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->storage = other.storage;
        this->maxSize = other.maxSize;
    }
    return *this;
}

void	Span::addNumber(unsigned int element)
{
	std::cout << "Inserting the number " << element << " in the Span." << std::endl;
	if (this->storage.size() == maxSize)
		throw std::length_error("Span is full.");
	this->storage.push_back(element);
		
}

unsigned int	Span::shortestSpan() const
{
	if (this->storage.size() <= 1)
		throw std::length_error("Span is too short.");
	
	unsigned int shortest_span = 2147483648;	
	std::vector<unsigned int> temp = this->storage;	
	std::sort(temp.begin(), temp.end());
	for (unsigned long i = 0; i < temp.size() - 1; i++)
	{
		if (temp[i + 1] - temp[i] < shortest_span)
			shortest_span = temp[i + 1] - temp[i];
	}
	return shortest_span;	
}

unsigned int	Span::longestSpan() const
{
	if (this->storage.size() <= 1)
		throw std::length_error("Span is too short.");
	
	std::vector<unsigned int> temp = this->storage;
	std::sort(temp.begin(), temp.end());
	unsigned int largest_span = temp[this->maxSize - 1] - temp[0];
	return largest_span;
}

std::vector<unsigned int>&  Span::getStorage()
{
	return this->storage;
}

unsigned int                Span::get_maxSize()
{
	return this->maxSize;
}

Span::~Span()
{
    std::cout << "Destructor for a Span was called." << std::endl;
}