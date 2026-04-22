/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:08:46 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/28 18:04:36 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <ctime>
#include <cstdlib>

enum e_random
{
    INT,
    CHAR,
    STRING
};

template  <typename Template>
void    swap(Template& a, Template& b)
{
    Template    tmp;

    tmp = a;
    a = b;
    b = tmp;
    return ;
}

template <typename Template>
Template&   min(Template& a, Template& b)
{
    if (a < b)
        return a;
    return b;
}

template    <typename Template>
Template&   max(Template& a, Template& b)
{
    if (a > b)
        return a;
    return b;
}


#endif