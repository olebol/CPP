/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:27:24 by opelser           #+#    #+#             */
/*   Updated: 2024/02/13 19:13:36 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>

namespace PmergeMe
{
	template <class Container, typename Iterator>
	void
	insertionSort(Iterator begin, Iterator end)
	{
		for (Iterator it = begin; it != end; it++)
		{
			Iterator		current = it;
			Iterator		previous = std::prev(current);
			
			while (current != begin && *current < *previous)
			{
				std::iter_swap(current, previous);

				current--;
				previous--;
			}
		}
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
		if (std::distance(begin, end) <= 10)
		{
			// Use insertion sort for small containers
			PmergeMe::insertionSort<Container, Iterator>(begin, std::next(end));
		}
		else
		{
			// Use merge sort for large containers
			Iterator		mid = std::next(begin, std::distance(begin, end) / 2);

			// Recursively sort the left and right halves
			PmergeMe::sort(container, begin, mid);
			PmergeMe::sort(container, std::next(mid), end);
			PmergeMe::mergeSort<Container, Iterator>(begin, mid, end);
		}
	}

	template <class Container>
	void
	sort(Container &container)
	{
		PmergeMe::sort<Container, typename Container::iterator>(container, container.begin(), std::prev(container.end()));
	}
}

#endif
