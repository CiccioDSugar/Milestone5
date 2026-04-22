/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:23:11 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/11/19 16:04:16 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <climits>
#include <iterator>
#include <sys/time.h>

class PmergeMeVector
{
    private:
        std::vector<int>    _inputVector;
        
    public:

    /*----------------ORTHODOX CANONICAL FORM----------------*/
    
                    PmergeMeVector();
                    PmergeMeVector(const PmergeMeVector &other);
                    PmergeMeVector(std::vector<int> vect);
    PmergeMeVector& operator=(const PmergeMeVector &other);
                    ~PmergeMeVector();

    /*----------------Member functions----------------*/
    
    std::vector<int>            sorter(const std::vector<int> input);
    int                         binary_search(const std::vector<int>& vect, int value, int limitIndex);
    std::vector<int>            getVect();
    size_t                      jacobsthal(size_t n);
    std::vector<size_t>         buildJacobSequence(size_t n);
    std::vector<int>::iterator  binary(std::vector<int>& vec, int value);
};

class PmergeMeDeque
{
    private:
        std::deque<int>     _inputDeque;

    public:
    
    /*----------------ORTHODOX CANONICAL FORM----------------*/
    
                    PmergeMeDeque();
                    PmergeMeDeque(const PmergeMeDeque &other);
                    PmergeMeDeque(std::deque<int> deq);
    PmergeMeDeque&  operator=(const PmergeMeDeque &other);
                    ~PmergeMeDeque();
                    
    /*----------------Member functions----------------*/
    
    std::deque<int>             sorter(const std::deque<int> deque);
    int                         binary_search(const std::deque<int>& vect, int value, int limitIndex);
    std::deque<int>             getVect();
    size_t                      jacobsthal(size_t n);
    std::deque<size_t>          buildJacobSequence(size_t n);
    std::deque<int>::iterator   binary(std::deque<int>& vec, int value);

};

bool    parse_input(int ac, char **av);
bool    check_doubles(int ac, char **av);
void    print_before(int ac, char **av);
void    print_after_vect(const std::vector<int>& vect);
void    print_after_deque(const std::deque<int>& deque);
double  get_time_us();

#endif