/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:11:55 by opelser           #+#    #+#             */
/*   Updated: 2024/01/31 20:21:06 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Array.hpp"

int main(void)
{
	// Test with int
	Array<int>		arr(5);

	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = i;

	std::cout << "arr.size() = " << arr.size() << std::endl;

	for (size_t i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

	// Test with std::string
	Array<std::string>	str(3);

	for (size_t i = 0; i < str.size(); i++)
		str[i] = "Hello World " + std::to_string(i);

	std::cout << "str.size() = " << str.size() << std::endl;

	for (size_t i = 0; i < str.size(); i++)
		std::cout << "str[" << i << "] = " << str[i] << std::endl;

	// Test with char
	Array<char>		c(8);
	
	for (size_t i = 0; i < c.size(); i++)
		c[i] = 'a' + i;

	std::cout << "c.size() = " << c.size() << std::endl;

	for (size_t i = 0; i < c.size(); i++)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	// Test out of range
	try
	{
		std::cout << "arr[5] = " << arr[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	try
	{
		std::cout << "str[-1] = " << str[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return (0);
}
