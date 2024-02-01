/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 16:09:21 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include "../include/easyfind.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
		{
			std::cerr << RED << "Usage: " << av[0] << " <value>" << RESET << std::endl;
			return (1);
		}

		int							value = std::stoi(av[1]);
		std::vector<int>			vec = {1, 2, 3, 4, 5};
		std::vector<int>::iterator	iter = easyfind(vec, value);

		std::cout << "Found value [" << value << "] at container index: " << std::distance(vec.begin(), iter) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	return (0);
}
