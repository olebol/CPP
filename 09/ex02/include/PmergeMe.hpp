/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:27:24 by opelser           #+#    #+#             */
/*   Updated: 2024/02/12 19:49:24 by opelser          ###   ########.fr       */
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
	template <class Container, typename Iterator>
	void
	printContainer(Container &container)
	{
		Iterator	it = container.begin();

		while (it != container.end())
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
	}

	template <class Container, typename Iterator>
	void
	mergeSort(Iterator begin, Iterator mid, Iterator end)
	{
		Container		left(begin, ++mid);
		Container		right(mid, ++end);

		Iterator		leftIt = left.begin();
		Iterator		rightIt = right.begin();

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

	template <class Container, typename Iterator>
	void
	sort(Container &container, Iterator begin, Iterator end)
	{
		if (std::distance(container.begin(), end) <= std::distance(container.begin(), begin))
			return ;

		// Get the middle of the container
		Iterator		mid = begin;

		std::advance(mid, std::distance(begin, end) / 2);

		// Recursively sort the left and right halves
		PmergeMe::sort(container, begin, mid);
		PmergeMe::sort(container, std::next(mid), end);
		PmergeMe::mergeSort<Container, Iterator>(begin, mid, end);
	}
}

#endif
