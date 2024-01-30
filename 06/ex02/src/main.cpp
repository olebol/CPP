/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:29:22 by opelser           #+#    #+#             */
/*   Updated: 2024/01/30 16:54:39 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <cstdlib>

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base	*generate(void)
{
	Base	*ptr;

	srand(time(NULL));

	switch (rand() % 3)
	{
		case 0:
			ptr = new A;
			break ;

		case 1:
			ptr = new B;
			break ;

		case 2:
			ptr = new C;
			break ;
	}

	return (ptr);
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr) != nullptr)
		std::cout << "type is: A" << std::endl;
	else if (dynamic_cast<B *>(ptr) != nullptr)
		std::cout << "type is: B" << std::endl;
	else if (dynamic_cast<C *>(ptr) != nullptr)
		std::cout << "type is: C" << std::endl;
	else
		std::cout << "type is: UNKNOWN" << std::endl;
}

void	identify(Base &p)
{
	// Test for A
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "type is: A" << std::endl;
	}
	catch (std::exception &e)
	{
		// Test for B
		try
		{
			(void) dynamic_cast<B &>(p);
			std::cout << "type is: B" << std::endl;
		}
		catch (std::exception &e)
		{
			// Test for C
			try
			{
				(void) dynamic_cast<C &>(p);
				std::cout << "type is: C" << std::endl;
			}
			// Handle no match
			catch (std::exception &e)
			{
				std::cout << "type is: UNKNOWN" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base	*ptr = generate();

	identify(ptr);
	identify(*ptr);

	return (0);
}
