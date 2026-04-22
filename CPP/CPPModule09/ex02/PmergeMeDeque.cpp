
#include "PmergeMe.hpp"


PmergeMeDeque::PmergeMeDeque()
{

}

PmergeMeDeque::PmergeMeDeque(std::deque<int> deque)
{
    this->_inputDeque = deque;
}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &other)
{
    this->_inputDeque = other._inputDeque;
}

PmergeMeDeque&  PmergeMeDeque::operator=(const PmergeMeDeque &other)
{
    if (this != &other)
        this->_inputDeque = other._inputDeque;
    return *this;
}

PmergeMeDeque::~PmergeMeDeque()
{

}

size_t PmergeMeDeque::jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::deque<size_t>     PmergeMeDeque::buildJacobSequence(size_t n)
{
    std::deque<size_t> sequence;

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

std::deque<int>::iterator      PmergeMeDeque::binary(std::deque<int>& vec, int value)
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

std::deque<std::pair<int, int> >   make_pair(std::deque<int> &toPair)
{
    std::deque<std::pair<int, int> >   pairVect;

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

std::deque<int>            PmergeMeDeque::sorter(const std::deque<int> input)
{
    
    std::deque<int>                     mainVect;
    std::deque<int>                     minorVect;
    std::deque<int>                     tmpVect;
    std::deque<std::pair<int, int> >    pairVect;
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

    std::deque<int> orderedMinor;
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
    std::deque<int> sortedVect = mainVect;
    std::deque<size_t> jacobsthalSequence = buildJacobSequence(orderedMinor.size());
    std::deque<bool> inserted(orderedMinor.size(), false);
    sortedVect.insert(sortedVect.begin(), orderedMinor[0]);
    inserted[0] = true;
    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
    {
        size_t idx = jacobsthalSequence[i];

        if (idx <= orderedMinor.size() && !inserted[idx])
        {
            int val = orderedMinor[idx];
            std::deque<int>::iterator pos = binary(sortedVect, val);
            sortedVect.insert(pos, val);
            inserted[idx] = true;
        }
    }
    for (size_t i = 1; i < orderedMinor.size(); i++)
    {
        if (!inserted[i])
        {
            int tmpVal = orderedMinor[i];
            std::deque<int>::iterator pos = binary(sortedVect, tmpVal);
            sortedVect.insert(pos, tmpVal);
            inserted[i] = true;
        }
    }

    return sortedVect;
}

void    print_after_deque(const std::deque<int>& deque)
{
    std::cout << " After:  ";
    for (size_t i = 0; i < deque.size(); i++)
    {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
}