/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 17:02:48 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include "../include/easyfind.hpp"

int main(void)
{
	std::vector<int>::iterator	iter;
	std::vector<int>			vec = {1, 2, 3, 4, 5};
	int							value = 3;
	
	iter = easyfind(vec, value);

	if (iter == vec.end())
		std::cout << RED << "Value [" << value << "] not found in container" << RESET << std::endl;
	else
		std::cout << GREEN << "Found value [" << value << "] at container index: " << std::distance(vec.begin(), iter) << RESET << std::endl;

	return (0);
}
