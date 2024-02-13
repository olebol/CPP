/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/13 19:41:41 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include "../include/StopWatch.hpp"

#include <iostream>
#include <algorithm>

#include <list>
#include <vector>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

template <class Container>
void
printContainer(Container &container)
{
	typename Container::iterator	it = container.begin();

	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <class Container>
void
fillContainer(Container &container, int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string		arg(av[i]);

		for (char c : arg)
		{
			if (std::isdigit(c) == false)
				throw (std::invalid_argument("All arguments must be positive integers"));
		}

		int		num = std::stoi(arg);

		container.push_back(num);
	}
}

int
main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << RED << "Usage: ./ex02 <int> ..." << RESET << std::endl;
		return (1);
	}

	try
	{
		StopWatch			stopwatch;

		// Sort vec (should be done with merge-insertion sort algorithm)
		{
			std::vector<int>	vec;

			fillContainer(vec, ac, av);

			std::cout << "Before: ";
			printContainer(vec);

			stopwatch.start();
			PmergeMe::sort(vec);
			stopwatch.stop();

			std::cout << "After: ";
			printContainer(vec);
			std::cout << std::endl;

			std::cout << "Elapsed time for std::vector<int>:\t" << stopwatch.getElapsed() << " microseconds" << std::endl;
		}

		// Sort lst (should be done with merge-insertion sort algorithm)
		{
			std::list<int>		lst;

			fillContainer(lst, ac, av);

			stopwatch.start();
			PmergeMe::sort(lst);
			stopwatch.stop();

			std::cout << "Elapsed time for std::list<int>:\t" << stopwatch.getElapsed() << " microseconds" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		return (1);
	}

	return (0);
}
