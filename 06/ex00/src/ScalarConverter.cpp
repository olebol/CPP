/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:28:02 by opelser           #+#    #+#             */
/*   Updated: 2024/01/25 21:23:59 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip>

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
	int			num = std::atoi(str.c_str());

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
	float		num = std::atof(str.c_str());

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
	double		num = std::strtod(str.c_str(), NULL);

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
	std::cout << "int: " << static_cast<int>(num) << std::endl;

	// float
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;

	// double
	std::cout << "double: " << num << std::endl;
}

static e_type	getType(const std::string &str)
{
	// char
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);

	// input edge cases
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (UNKNOWN);
	}
	if (str.find("..") != std::string::npos || str[str.length() - 1] == '.')
		return (UNKNOWN);

	// float
	if ((str.find('.') != std::string::npos && str.find('f') == str.length() - 1)
		|| (str == "nanf" || str == "-inff" || str == "+inff"))
		return (FLOAT);

	// double
	if ((str.find('.') != std::string::npos && str.find('f') == std::string::npos)
		|| (str == "nan" || str == "-inf" || str == "+inf"))
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
	// std::cout << std::setprecision(10);

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
