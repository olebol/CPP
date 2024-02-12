/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:27:24 by opelser           #+#    #+#             */
/*   Updated: 2024/02/12 18:41:00 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>

namespace PmergeMe
{
	class NegativeValueException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Negative value");
			}
	};

	// Delete this
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

	template <class Container, typename iter>
	void mergeSort(iter begin, iter mid, iter end)
	{
		Container		left(begin, ++mid);
		Container		right(mid, ++end);

		iter leftIt = left.begin();
		iter rightIt = right.begin();

		while (leftIt != left.end() && rightIt != right.end())
		{
			if (*leftIt < *rightIt)
			{
				*begin = *leftIt;
				leftIt++;
			}
			else
			{
				*begin = *rightIt;
				rightIt++;
			}
			begin++;
		}

		while (leftIt != left.end())
		{
			*begin = *leftIt;
			leftIt++;
			begin++;
		}

		while (rightIt != right.end())
		{
			*begin = *rightIt;
			rightIt++;
			begin++;
		}
	}

	template <class Container, typename iter>
	void
	sort(Container &container, iter begin, iter end)
	{
		if (std::distance(container.begin(), end) <= std::distance(container.begin(), begin))
			return ;

		// Set the middle of the container
		iter		mid = begin;

		std::advance(mid, std::distance(begin, end) / 2);

		// Recursively sort the left and right halves
		PmergeMe::sort(container, begin, mid);
		PmergeMe::sort(container, std::next(mid), end);
		PmergeMe::mergeSort<Container, iter>(begin, mid, end);
	}
}

#endif
