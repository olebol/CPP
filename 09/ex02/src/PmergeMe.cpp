/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:27:49 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 22:27:56 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

PmergeMe::PmergeMe(void)
{
	std::cout << GREEN << "PmergeMe: Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	std::cout << GREEN << "PmergeMe: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	std::cout << GREEN << "PmergeMe: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
	}

	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	std::cout << RED << "PmergeMe: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


