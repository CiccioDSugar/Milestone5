/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:04:34 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/10 16:11:27 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
            std::vector<unsigned int>	storage;
		    unsigned int 		maxSize;
            /*Orthodox Canonical Form*/
    public:
                    Span();
        			Span(unsigned int capacity);
        			Span(const Span &other);
        const Span& operator=(const Span &other);
        			~Span();
        std::vector<unsigned int>&  getStorage();
        unsigned int                get_maxSize();
    /*Member Functions*/
        void                       	addNumber(unsigned int element);
		template <typename T>
        void	addMultipleNumber(T start, T end)
		{
            if (this->storage.size() + (end - start) >= maxSize)
                throw std::length_error("Span is full.");
            this->storage.insert(this->storage.end(), start, end);
		}
        unsigned int    shortestSpan()	const;
        unsigned int    longestSpan()	const;
};

#endif