/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:27:24 by opelser           #+#    #+#             */
/*   Updated: 2024/02/12 20:04:48 by opelser          ###   ########.fr       */
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

		// Merge the left and right halves into the original container
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

		// Copy the remaining elements of left and right
		std::copy(leftIt, left.end(), begin);
		std::copy(rightIt, right.end(), begin);
	}

	template <class Container, typename Iterator>
	void
	sort(Container &container, Iterator begin, Iterator end)
	{
		// If the current sub-container is empty, break the recursion
		if (std::distance(begin, end) <= 0)
			return ;

		// Get the middle of the container
		Iterator		mid = std::next(begin, std::distance(begin, end) / 2);

		// Recursively sort the left and right halves
		PmergeMe::sort(container, begin, mid);
		PmergeMe::sort(container, std::next(mid), end);
		PmergeMe::mergeSort<Container, Iterator>(begin, mid, end);
	}
}

#endif
