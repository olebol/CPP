/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:28:02 by opelser           #+#    #+#             */
/*   Updated: 2024/01/29 15:44:37 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

ScalarConverter::ScalarConverter(void)
{
	std::cout << GREEN << "ScalarConverter: Default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &str)
{
	std::cout << GREEN << "ScalarConverter: Parametric constructor called" << RESET << std::endl;

	(void) str;
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	std::cout << GREEN << "ScalarConverter: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	std::cout << GREEN << "ScalarConverter: Assignment operator called" << RESET << std::endl;
	
	if (this != &rhs)
	{
		// Perform deep copy
	}

	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Helper Functions                             //
// ************************************************************************** //

static void	convertChar(const char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	convertInt(const std::string &str)
{
	int				num;

	// convert string to int
	try
	{
		num = std::stoi(str);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << RED << "Exception caught: Invalid argument - " << e.what() << RESET << std::endl;
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "Exception caught: Out of range - " << e.what() << RESET << std::endl;
		return ;
	}


	// char
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;

	// int
	std::cout << "int: " << num << std::endl;

	// float
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;

	// double
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void	convertFloat(const std::string &str)
{
	float		num;

	// convert string to float
	try
	{
		num = std::stof(str);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << RED << "Exception caught: Invalid argument - " << e.what() << RESET << std::endl;
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "Exception caught: Out of range - " << e.what() << RESET << std::endl;
		return ;
	}

	// nanf -inff +inff
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		return ;
	}

	// char
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;

	// int
	std::cout << "int: " << static_cast<int>(num) << std::endl;

	// float
	std::cout << "float: " << num << "f" << std::endl;

	// double
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void	convertDouble(const std::string &str)
{
	double		num;

	// convert string to double
	try
	{
		num = std::stod(str);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << RED << "Exception caught: Invalid argument - " << e.what() << RESET << std::endl;
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << RED << "Exception caught: Out of range - " << e.what() << RESET << std::endl;
		return ;
	}

	// nan -inf +inf
	if (str == "nan" || str == "-inf" || str == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << num << std::endl;
		return ;
	}

	// char
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;

	// int
	if (num > std::numeric_limits<int>::max() ||
		num < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	// float
	if (num > std::numeric_limits<float>::max() ||
		num < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;

	// double
	std::cout << "double: " << num << std::endl;
}

static e_type	getType(const std::string &str)
{
	// char
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);

	// pseudo literals
	if ((str == "nanf" || str == "-inff" || str == "+inff"))
		return (FLOAT);
	if ((str == "nan" || str == "-inf" || str == "+inf"))
		return (DOUBLE);

	// input edge cases
	size_t		len = str.length() - 1;
	for (size_t i = 0; i < len; i++)
	{
		if (std::isdigit(str[i]) == false && str[i] != '.')
			return (UNKNOWN);
	}
	if (str[len] == '.')
		return (UNKNOWN);
	if (std::isdigit(str[len]) == false && str[len] != 'f')
		return (UNKNOWN);
	if (str.find("..") != std::string::npos)
		return (UNKNOWN);

	// float
	if (str.find('.') != std::string::npos && str.find('f') == len)
		return (FLOAT);

	// double
	if (str.find('.') != std::string::npos && str.find('f') == std::string::npos)
		return (DOUBLE);

	// int
	return (INT);
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void		ScalarConverter::convert(const std::string &str)
{
	// Set precision
	std::cout << std::fixed << std::setprecision(1);

	switch (getType(str))
	{
		case CHAR:
			std::cout << "TYPE IS CHAR\n" << std::endl;
			convertChar(str[0]);
			break ;

		case INT:
			std::cout << "TYPE IS INT\n" << std::endl;
			convertInt(str);
			break ;

		case FLOAT:
			std::cout << "TYPE IS FLOAT\n" << std::endl;
			convertFloat(str);
			break ;

		case DOUBLE:
			std::cout << "TYPE IS DOUBLE\n" << std::endl;
			convertDouble(str);
			break ;

		default:
			std::cout << "TYPE IS UNKNOWN\n" << std::endl;
			std::cout << RED << "Error: Invalid input" << RESET << std::endl;
			break ;
	}
}
