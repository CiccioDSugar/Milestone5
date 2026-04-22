/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:05:55 by fzuccaro          #+#    #+#             */
/*   Updated: 2026/01/22 16:25:56 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    


    std::list<int> lstack;
    
    lstack.push_back(5);
    lstack.push_back(17);
    
    std::cout << lstack.back() << std::endl;
    
    lstack.pop_back();
    
    std::cout << lstack.size() << std::endl;
    
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    
    std::list<int>::iterator IT = lstack.begin();
    std::list<int>::iterator ITE = lstack.end();
    
    ++IT;
    --IT;
    
    while (IT != ITE)
    {
        std::cout << *IT << std::endl;
        ++IT;
    }
    
    std::list<int> f(lstack);
    

    return 0;
}