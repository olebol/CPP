/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:28:02 by opelser           #+#    #+#             */
/*   Updated: 2024/01/25 20:51:45 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip>

#define GREEN "33[32m"
#define RED "33[31m"
#define RESET "33[0m"

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
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
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

	// double
	std::cout << "double: " << static_cast<double>(num) << std::endl;

	// float
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
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

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void		ScalarConverter::convert(const std::string &str)
{
	std::cout << "str: " << str << std::endl;

	// Set precision
	// std::cout << std::setprecision(10) << std::endl;

	convertChar(str[0]);

	convertInt(str);

	convertFloat(str);
	
	convertDouble(str);
}
