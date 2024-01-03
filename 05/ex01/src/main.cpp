/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2024/01/03 21:38:53 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <exception>

int main(void)
{
	Bureaucrat		bob("Bob", 1);
	Bureaucrat		jim("Jim", 150);

	std::cout << bob << jim;

	bob.demote();
	jim.promote();

	std::cout << bob << jim;

	bob.promote();
	bob.promote();
	jim.demote();
	jim.demote();

	std::cout << bob << jim;

	try
	{
		Bureaucrat		alex("Alex", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat		alex("Alex", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
