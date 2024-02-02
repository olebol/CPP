/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:51 by opelser           #+#    #+#             */
/*   Updated: 2024/02/02 18:07:41 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <iostream>
#include <fstream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(void)
	:	_exchangeRates()
{
	std::cout << GREEN << "BitcoinExchange: Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string &filename)
{
	std::cout << GREEN << "BitcoinExchange: Parameter constructor called" << RESET << std::endl;

	parseData(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	std::cout << GREEN << "BitcoinExchange: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

BitcoinExchange &
BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	std::cout << GREEN << "BitcoinExchange: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy

		_exchangeRates = rhs._exchangeRates;
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << RED << "BitcoinExchange: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Adding rates                                //
// ************************************************************************** //

void
BitcoinExchange::addRate(std::string date, double rate)
{
	_exchangeRates[date] = rate;
}

void
BitcoinExchange::parseData(std::string &filename)
{
	// Parse the file and add the rates to the map
	try
	{
		// Open the file
		std::string		line;
		std::ifstream	file(filename);

		if (file.good() == false || file.is_open() == false)
			throw (std::ifstream::failure("Error: could not open file"));

		do
		{
			// Read the file
			std::getline(file, line);

			// Parse the line
			std::string		date = line.substr(0, line.find(','));
			double			rate = std::stod(line.substr(line.find(',') + 1));

			// Add the rates to the map
			addRate(date, rate);
		}
		while (file.good() == true);

		// Close the file
		file.close();		
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << RED << "Exception caught: Invalid argument for function - " << e.what() << RESET << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "Exception caught: Rate is out of range for function - " << e.what() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

// ************************************************************************** //
//                               Public Methods                              //
// ************************************************************************** //

double
BitcoinExchange::getRate(std::string &date) const
{
	// Find the rate for the given date
	std::map<std::string, double>::const_iterator		it;
	
	it = _exchangeRates.find(date);

	if (it != _exchangeRates.end())
		return (it->second);
	else
		throw (BitcoinExchange::NoRateAvailable());

	return (0);
}

double
BitcoinExchange::exchange(std::string &date, double amount) const
{
	// Exchange the given amount for the given date
	double	rate = getRate(date);

	if (amount < 0 || amount > 1000)
		throw (BitcoinExchange::invalidValue());

	return (amount * rate);
}


