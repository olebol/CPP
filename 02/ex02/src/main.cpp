/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/12 17:29:02 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

#include <iostream>

void	comparison(Fixed const &a, Fixed const &b)
{
	if (a < b == true)
		std::cout << "Correct result" << std::endl;
	else
		std::cout << "Incorrect result" << std::endl;

	if (a > b == false)
		std::cout << "Correct result" << std::endl;
	else
		std::cout << "Incorrect result" << std::endl;
	
	if (a <= b == true)
		std::cout << "Correct result" << std::endl;
	else
		std::cout << "Incorrect result" << std::endl;

	if (a >= b == false)
		std::cout << "Correct result" << std::endl;
	else
		std::cout << "Incorrect result" << std::endl;

	if (a == b == false)
		std::cout << "Correct result" << std::endl;
	else
		std::cout << "Incorrect result" << std::endl;
	
	if (a != b == true)
		std::cout << "Correct result" << std::endl;
	else
		std::cout << "Incorrect result" << std::endl;
}

int main(void)
{
	Fixed			a;
	Fixed const		b(Fixed(5.05f) * Fixed(2));

	comparison(a, b);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}