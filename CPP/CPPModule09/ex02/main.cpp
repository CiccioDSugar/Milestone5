/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:23:35 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/11/19 16:01:26 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


/* int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
        return 1;
    }

    if (!parse_input(ac, av))
        return 1;

    print_before(ac, av);
    
    std::cout << "====================== Testing Vector ======================" << std::endl;
    std::vector<int> input;
    for (int i = 1; i < ac; i++)
        input.push_back(std::atoi(av[i]));
    PmergeMeVector toSort(input);
    time_t *start = 0;
    time(start);
    std::vector<int> result = toSort.sorter(input);
    time_t *end = 0;
    std::cout << time(end) << std::endl;
    print_after_vect(result);
    
    std::cout << "====================== Testing Deque ======================" << std::endl;
    std::deque<int> inputDeque;
    for (int i = 1; i < ac; i++)
        inputDeque.push_back(std::atoi(av[i]));
    PmergeMeDeque   toBeSorted(inputDeque);
    time_t *starting = 0;
    time(starting);
    std::deque<int> DequeResult = toBeSorted.sorter(inputDeque);
    time_t *ending = 0;
    std::cout << time(ending) << std::endl;
    print_after_deque(DequeResult);
    
    return 0;
}
 */

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
        return 1;
    }

    if (!parse_input(ac, av))
        return 1;

    print_before(ac, av);
    
    std::cout << "====================== Testing Vector ======================" << std::endl;
    std::vector<int> input;
    for (int i = 1; i < ac; i++)
        input.push_back(std::atoi(av[i]));
    PmergeMeVector toSort(input);
    double start = get_time_us();
    std::vector<int> result = toSort.sorter(input);
    double end = get_time_us();
    std::cout << "Time elapsed: " << (end - start) << " us" << std::endl;
    print_after_vect(result);
    
    std::cout << "====================== Testing Deque ======================" << std::endl;
    std::deque<int> inputDeque;
    for (int i = 1; i < ac; i++)
        inputDeque.push_back(std::atoi(av[i]));
    PmergeMeDeque toBeSorted(inputDeque);
    double starting = get_time_us();
    std::deque<int> DequeResult = toBeSorted.sorter(inputDeque);
    double ending = get_time_us();
    std::cout << "Time elapsed: " << (ending - starting) << " us" << std::endl;
    print_after_deque(DequeResult);
    
    return 0;
}