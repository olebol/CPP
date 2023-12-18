/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 22:39:54 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include <iostream>
#include <string>

void	checkNormal(void)
{
	const Animal*		animal = new Animal();
	const Animal*		cat = new Cat();
	const Animal*		dog = new Dog();

	std::cout << std::endl;

	// Print types
	std::cout << animal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;

	std::cout << std::endl;

	// Make sounds
	animal->makeSound();
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();

	std::cout << std::endl;

	// Free memory
	delete animal;
	delete cat;
	delete dog;

	std::cout << std::endl;
}

void	checkWrong(void)
{
	const WrongAnimal*		wrongAnimal = new WrongAnimal();
	const WrongAnimal*		wrongCat = new WrongCat();

	std::cout << std::endl;

	// Print types
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << std::endl;

	// Make sounds
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;

	// Free memory
	delete wrongAnimal;
	delete wrongCat;
}

int main()
{
	checkNormal();
	checkWrong();

	return (0);
}
