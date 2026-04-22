/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:48:53 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/29 11:31:08 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename Template1, typename Template2>
void    iter(Template1 ptr[], const size_t size, Template2 f )
{
    for (size_t i = 0; i < size; ++i)
        f(ptr[i]);
}

#endif