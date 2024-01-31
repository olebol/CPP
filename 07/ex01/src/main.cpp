/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:16 by opelser           #+#    #+#             */
/*   Updated: 2024/01/31 16:28:03 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/iter.hpp"

int main(void)
{
	int			array_int[5] = {0, 1, 2, 3, 4};
	float		array_float[5] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
	std::string	array_string[5] = {"zero", "one", "two", "three", "four"};

	::iter(array_int, 5, ::print);
	std::cout << std::endl;

	::iter(array_float, 5, ::print);
	std::cout << std::endl;

	::iter(array_string, 5, ::print);
	std::cout << std::endl;

	return (0);
}
