/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:18:23 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/10 17:12:23 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator  begin();
        iterator  end();
};

template <typename T>
typename std::stack<T>::container_type::iterator  MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator  MutantStack<T>::end()        
{
    return (this->c.end());
}

#endif