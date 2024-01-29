/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:23:36 by opelser           #+#    #+#             */
/*   Updated: 2024/01/29 17:36:52 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main(void)
{
	Data			*data;
	Data			*data2;
	uintptr_t		serialized;

	data = new Data("Bob", 42);
	std::cout << "data before deserialization: " << data << std::endl;
	std::cout << "data2 before deserialization: " << data2 << std::endl;

	serialized = Serializer::serialize(data);
	std::cout << "serialized: " << serialized << std::endl;
	
	data = Serializer::deserialize(serialized);
	std::cout << "data after deserialization: " << data << std::endl;

	data2 = Serializer::deserialize(serialized);
	std::cout << "data2 after deserialization: " << data2 << std::endl;

	delete data2;

	return (0);
}
