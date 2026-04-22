/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:36:06 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/06 15:13:36 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename T>
typename T::const_iterator easyfind(const T& container, int n)
{
    typename T::const_iterator start = container.begin();
    typename T::const_iterator end = container.end();
    return (std::find(start, end, n));
}