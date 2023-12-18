/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 21:18:14 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

#include <iostream>
#include <string>

int main()
{
	const Animal*		animal = new Animal();
	const Animal*		cat = new Cat();
	const Animal*		dog = new Dog();

	std::cout << std::endl;

	std::cout << animal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;

	std::cout << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();

	std::cout << std::endl;

	delete animal;
	delete cat;
	delete dog;

	return (0);
}