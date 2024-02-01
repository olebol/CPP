/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:51 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 22:23:00 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << GREEN << "BitcoinExchange: Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	std::cout << GREEN << "BitcoinExchange: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	std::cout << GREEN << "BitcoinExchange: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << RED << "BitcoinExchange: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


