/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:11:49 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/28 15:59:40 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    static bool seeded = false;
    int         random;

    if (!seeded)
    {
        std::cout << "Generating a random object A, B or C." << std::endl  << std::endl;
        srand(time(NULL));
        seeded = true;
    }
    random = rand() % 3;
    if (random == 0)
    {
        std::cout << "Program generated an object of tipe A." << std::endl << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Program generated an object of tipe B." << std::endl << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Program generated an object of tipe C." << std::endl << std::endl;
        return new C();
    }
}

void    identify(Base* ptr)
{
    std::cout << "Trying to identify which POINTER we have." << std::endl << std::endl;

    if (dynamic_cast<A*>(ptr) != NULL)
        std::cout << "Pointer A was found." << std::endl << std::endl;
    else if (dynamic_cast<B*>(ptr) != NULL)
        std::cout << "Pointer B was found." << std::endl << std::endl;
    else if (dynamic_cast<C*>(ptr) != NULL)
        std::cout << "Pointer C was found." << std::endl << std::endl;
    return ;
}

void    identify(Base& ptr)
{
    std::cout << "Trying to identify which REFERENCE we have." << std::endl << std::endl;
    try
    {
        (void)dynamic_cast<A&>(ptr);
        std::cout << "Reference to an A object was found." << std::endl << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        
    }
    try
    {
        (void)dynamic_cast<B&>(ptr);
        std::cout << "Reference to a B object was found." << std::endl << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {

    }
    try
    {
        (void)dynamic_cast<C&>(ptr);
        std::cout << "Reference to a C object was found." << std::endl << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {

    }
    
}