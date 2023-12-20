/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/20 19:35:04 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

#include <iostream>
#include <string>

void	testBrain(void)
{
	// Create a Brain
	Brain		*brain = new Brain();

	// Fill the Brain with ideas
	brain->setIdea(0, "I should eat");
	brain->setIdea(1, "I should sleep");
	brain->setIdea(2, "I should play");

	// Display the Brain's ideas
	for (int i = 0; i < 3; i++)
		std::cout << "Brain: " << brain->getIdea(i) << std::endl;



	// Create a copy of the Brain
	Brain		*brain2 = new Brain(*brain);

	// Check if the copy is a deep copy
	for (int i = 0; i < 3; i++)
		std::cout << "Brain2: " << brain2->getIdea(i) << std::endl;

	// Change the first idea of the original Brain and check if the copy has changed
	brain->setIdea(0, "I should eat more");

	std::cout << "Brain: " << brain->getIdea(0) << std::endl;
	std::cout << "Brain2: " << brain2->getIdea(0) << std::endl;

	// Free the memory
	delete (brain);
	delete (brain2);
}

void	testDog(void)
{
	Dog			*dog = new Dog();
	
	dog->makeSound();
	
	dog->setIdea(0, "I should eat");
	dog->setIdea(1, "I should sleep");
	dog->setIdea(2, "I should play");

	for (int i = 0; i < 3; i++)
		std::cout << "Dog: " << dog->getIdea(i) << std::endl;

	// Create a copy
	Dog			*dog2 = new Dog(*dog);

	// Check if the copy is a deep copy
	for (int i = 0; i < 3; i++)
		std::cout << "Dog2: " << dog2->getIdea(i) << std::endl;

	delete (dog);
	delete (dog2);
}

void	testCat(void)
{
	Cat			*cat = new Cat();
	
	cat->makeSound();
	
	cat->setIdea(0, "I should eat");
	cat->setIdea(1, "I should sleep");
	cat->setIdea(2, "I should play");

	for (int i = 0; i < 3; i++)
		std::cout << "cat: " << cat->getIdea(i) << std::endl;

	// Create a copy
	Cat			*cat2 = new Cat(*cat);

	// Check if the copy is a deep copy
	for (int i = 0; i < 3; i++)
		std::cout << "cat2: " << cat2->getIdea(i) << std::endl;

	delete (cat);
	delete (cat2);
}

void	testAnimals(void)
{
	// Create an array of animals
	Animal	*animals[10];

	// Fill the animal array with 5 Dogs and 5 Cats
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	// Make them make noise
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	std::cout << std::endl;

	// Create a copy of the first Dog and then see if it is a deep copy
	Animal	*copy = new Dog(*(static_cast <Dog *> (animals[0])));

	std::cout << "Copy of the first Dog: " << std::endl;
	copy->makeSound();

	delete (copy);

	std::cout << std::endl;

	// Free the memory by calling the base class destructor
	for (int i = 0; i < 10; i++)
		delete (animals[i]);
}

int main()
{
	testBrain();

	std::cout << std::endl;

	testDog();

	std::cout << std::endl;

	testCat();

	std::cout << std::endl;

	testAnimals();

	return (0);
}
