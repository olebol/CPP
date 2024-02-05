/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/05 20:07:06 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"
#include <fstream>



static void
exchangeLine(const std::string &line, const BitcoinExchange &exchange)
{
	// Parse the line
	try
	{
		std::string		date = BitcoinExchange::convertToDate(line);
		double			rate = BitcoinExchange::convertToRate(line, line.find_first_of(" | ") + 3);
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


static void
exchangeAll(const std::string &filename, const BitcoinExchange &exchange)
{
	std::ifstream	file(filename);
	std::string		line;

	if (file.good() == false || file.is_open() == false)
			throw (std::ifstream::failure("Error: could not open file"));

	// Skip the first line
	std::getline(file, line);

	// Read the file
	int lineCount = 2;
	while (std::getline(file, line))
	{
		if (file.fail() == true)
			break ;

		std::cout << "Line " << lineCount++ << ": ";

		exchangeLine(line, exchange);
	}

	// Close the file
	file.close();
}

int
main(int ac, char **av)
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
