/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:51 by opelser           #+#    #+#             */
/*   Updated: 2024/02/05 20:13:33 by opelser          ###   ########.fr       */
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

static void
parseLine(const std::string &line, BitcoinExchange &exchange)
{
	// Parse the line
	try
	{
		std::string		date = BitcoinExchange::convertToDate(line);
		double			rate = BitcoinExchange::convertToRate(line, line.find_first_of(',') + 1);

		// Add the rates to the map
		exchange.addRate(date, rate);
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

void
BitcoinExchange::parseData(std::string &filename)
{
	// Parse the file and add the rates to the map
	try
	{
		// Open the file
		std::ifstream	file(filename);
		std::string		line;

		if (file.good() == false || file.is_open() == false)
			throw (std::ifstream::failure("Could not open file"));

		// Skip the first line
		std::getline(file, line);

		// Read the file
		while (std::getline(file, line))
		{
			if (file.fail() == true)
				break ;

			parseLine(line, *this);
		}

		// Close the file
		file.close();
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
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

// ************************************************************************** //
//                               Static Functions                             //
// ************************************************************************** //

std::string
BitcoinExchange::convertToDate(const std::string &input)
{
	if (input.size() < 10)
		throw (BitcoinExchange::InvalidDate());

	// Get the date
	std::string		date = input.substr(0, 10);

	if (date.size() != 10)
		throw (BitcoinExchange::InvalidDate());

	// Check the date format
	for (int i = 0; date[i]; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw (BitcoinExchange::InvalidDate());
		}
		else if (date[i] < '0' || date[i] > '9')
			throw (BitcoinExchange::InvalidDate());
	}

	// Check date limits
	try
	{
		int		year = std::stoi(date.substr(0, 4));
		int		month = std::stoi(date.substr(5, 2));
		int		day	= std::stoi(date.substr(8, 2));

		if ((year < 2009 || year > 2023) ||
			(month < 1 || month > 12) ||
			(day < 1 || day > 31))
			throw (BitcoinExchange::InvalidDate());
	}
	catch (std::exception &e)
	{
		throw (BitcoinExchange::InvalidDate());
	}

	return (date);
}

double
BitcoinExchange::convertToRate(const std::string &input, const size_t start)
{
	if (input.size() < start)
		throw (BitcoinExchange::InvalidValue());

	// Get the rate
	std::string		rate = input.substr(start);

	if (rate.empty() == true)
		throw (BitcoinExchange::InvalidValue());

	return (std::stod(rate));
}