/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:23:08 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/11/21 19:53:36 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>

bool    parse_input(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string line = av[i];
        for (unsigned long j = 0; j < line.length(); j++)
        {
            if (!isdigit(line[j]) || std::atof(line.c_str()) > INT_MAX)
            {
                std::cerr << "Error: parameter different from a positive integer was found." << std::endl;
                return false;
            }
        }
    }
    if (!check_doubles(ac, av))
    {
        std::cerr << "Error: duplicate are not allowed." << std::endl;
        return false;
    }
    return true;
}

bool    check_doubles(int ac, char **av)
{
    std::vector<int>    tmp;

    for (int i = 1; i < ac; i++)
    {
        tmp.push_back(atof(av[i]));
    }

    std::sort(tmp.begin(), tmp.end());
    
    for (size_t i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] == tmp[i - 1])
            return false;
    }
    return true;
}


std::vector<std::pair<int, int> >   make_pair(std::vector<int> &toPair)
{
    std::vector<std::pair<int, int> >   pairVect;

    for (size_t i = 0; i < toPair.size(); i += 2)
    {
        std::pair<int, int> _pair;
        if (toPair[i] < toPair[i+1])
        {
            _pair.first = toPair[i];
            _pair.second = toPair[i+1];
        }
        else
        {
            _pair.first = toPair[i+1];
            _pair.second = toPair[i];
        }
        pairVect.push_back(_pair);
    }
    return pairVect;
}

size_t PmergeMeVector::jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<size_t>     PmergeMeVector::buildJacobSequence(size_t n)
{
    std::vector<size_t> sequence;

    size_t k = 1;
    while (true)
    {
        size_t j = jacobsthal(k);
        if (j + 1 > n)
            break;

        sequence.push_back(j);
        k++;
    }
    return sequence;
}

std::vector<int>::iterator      PmergeMeVector::binary(std::vector<int>& vec, int value)
{
    size_t left = 0;
    size_t right = vec.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (vec[mid] <= value)
            left = mid + 1;
        else
            right = mid;
    }
    return vec.begin() + left;
}

std::vector<int>            PmergeMeVector::sorter(const std::vector<int> input)
{
    
    std::vector<int>                    mainVect;
    std::vector<int>                    minorVect;
    std::vector<int>                    tmpVect;
    std::vector<std::pair<int, int> >   pairVect;
    bool    odd_size = false;
    int     struggler = -1;
    if (input.size() <= 1)
        return input;
    tmpVect = input;
    if (tmpVect.size() % 2 != 0)
    {
        odd_size = true;
        struggler = tmpVect.back();
        tmpVect.pop_back();
    }
    pairVect = make_pair(tmpVect);
    for (size_t i = 0; i < pairVect.size(); i++)
    {
        mainVect.push_back(pairVect[i].second);
        minorVect.push_back(pairVect[i].first);
    }
    if (odd_size)
        minorVect.push_back(struggler);
    mainVect = sorter(mainVect);

    std::vector<int> orderedMinor;
    for (size_t i = 0; i < mainVect.size(); i++)
    {
        for (size_t j = 0; j < pairVect.size(); j++)
        {
            if (mainVect[i] == pairVect[j].second)
                orderedMinor.push_back(pairVect[j].first);
        }
    }
    if (odd_size)
        orderedMinor.push_back(struggler);
    std::vector<int> sortedVect = mainVect;
    std::vector<size_t> jacobsthalSequence = buildJacobSequence(orderedMinor.size());
    std::vector<bool> inserted(orderedMinor.size(), false);
    sortedVect.insert(sortedVect.begin(), orderedMinor[0]);
    inserted[0] = true;
    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
    {
        size_t idx = jacobsthalSequence[i];

        if (idx <= orderedMinor.size() && !inserted[idx])
        {
            int val = orderedMinor[idx];
            std::vector<int>::iterator pos = binary(sortedVect, val);
            sortedVect.insert(pos, val);
            inserted[idx] = true;
        }
    }
    for (size_t i = 1; i < orderedMinor.size(); i++)
    {
        if (!inserted[i])
        {
            int tmpVal = orderedMinor[i];
            std::vector<int>::iterator pos = binary(sortedVect, tmpVal);
            sortedVect.insert(pos, tmpVal);
            inserted[i] = true;
        }
    }

    return sortedVect;
}



void    print_before(int ac, char **av)
{
    std::cout << " Before: ";
    for (int i = 1; i < ac; i++)
    {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
}

void print_after_vect(const std::vector<int>& vect)
{
    std::cout << " After:  ";
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int>    PmergeMeVector::getVect()
{
    return this->_inputVector;
}

void    print_time()
{
    
}

PmergeMeVector::PmergeMeVector()
{
    
}

PmergeMeVector::PmergeMeVector(std::vector<int> vect)
{
    this->_inputVector = vect;
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector &other)
{
    this->_inputVector = other._inputVector;
}

PmergeMeVector&     PmergeMeVector::operator=(const PmergeMeVector &other)
{
    if (this != &other)
        this->_inputVector = other._inputVector;
    return *this;
}

PmergeMeVector::~PmergeMeVector()
{
    
}

double    get_time_us()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}