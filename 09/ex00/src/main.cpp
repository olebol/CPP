/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/05 18:44:27 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"
#include <fstream>

static std::string		getDate(std::string &input)
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

	if (date[5] >= '2' || date[6] >= '4')
		throw (BitcoinExchange::InvalidDate());

	return (date);
}

static std::string		getRate(std::string &input)
{
	if (input.size() < 13)
		throw (BitcoinExchange::InvalidValue());

	// Get the rate
	std::string		rate = input.substr(12);

	if (rate.empty() == true)
		throw (BitcoinExchange::InvalidValue());

	return (rate);
}

static void				exchangeAll(const std::string &filename, const BitcoinExchange &exchange)
{
	std::ifstream	file(filename);
	std::string		line;

	// Skip the first line
	std::getline(file, line);

	// Read the file
	while (std::getline(file, line))
	{
		if (file.fail() == true)
			break ;

		// Exchange the rate
		try
		{
			std::string		date = getDate(line);
			double			rate = std::stod(getRate(line));
			double			amount = exchange.exchange(date, rate);

			std::cout << date << " => " << rate << " = " << amount << std::endl;
		}
		catch (const std::invalid_argument &e)
		{
			std::cout << RED << "Exception caught during exchanging: Invalid argument for function - " << e.what() << RESET << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << "Exception caught during exchanging: Rate is out of range for function - " << e.what() << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "Exception caught during exchanging: " << e.what() << RESET << std::endl;
		}
	}

	// Close the file
	file.close();
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Usage: " << av[0] << " <filename>" << RESET << std::endl;
		return (1);
	}

	try
	{
		std::string			filename = "data.csv";
		BitcoinExchange		exchange(filename);

		exchangeAll(av[1], exchange);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}	
	
	return (0);
}
