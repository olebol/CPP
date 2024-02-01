/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 18:37:16 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include "../include/Span.hpp"

int main(void)
{
	try
	{
		Span		span(5);

		// Add numbers to the array
		span.addRange(5);

		for (int i = 0; i < 5; i++)
			std::cout << span.getNumber(i) << std::endl;

		// Try to add a number to a full array
		span.addNumber(6);
	}
	catch (std::exception &e)
	{
		std::cout << RED "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span		span(5);

		// Try to get a number from an empty array
		span.getNumber(0);
	}
	catch (std::exception &e)
	{
		std::cout << RED "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;

	return (0);
}
