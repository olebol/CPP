/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:51 by opelser           #+#    #+#             */
/*   Updated: 2024/02/05 18:40:16 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <iostream>
#include <fstream>

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

		if (file.fail() == true || file.is_open() == false)
			throw (std::ifstream::failure("Error: could not open file"));

		// Skip the first line
		std::getline(file, line);

		// Read the file
		while (std::getline(file, line))
		{
			if (file.fail() == true && line.empty() == true)
				break ;

			// Parse the line
			std::string		date = line.substr(0, line.find(','));
			double			rate = std::stod(line.substr(line.find(',') + 1));

			// Add the rates to the map
			addRate(date, rate);

			// Get the next line
			std::getline(file, line);
		}

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
	
	it = this->_exchangeRates.find(date);

	if (it != this->_exchangeRates.end())
		return (it->second);
	else
		return (this->_exchangeRates.lower_bound(date)->second);
}

double
BitcoinExchange::exchange(std::string &date, double amount) const
{
	// Check if the amount is valid
	if (amount < 0)
		throw (BitcoinExchange::NegativeValue());
	if (amount > 1000)
		throw (BitcoinExchange::ValueTooHigh());

	// Exchange the given amount for the given date
	return (amount * getRate(date));
}


