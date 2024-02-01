/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 22:06:11 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include "../include/MutantStack.hpp"

void	subject(void)
{
	std::cout << BLUE << "Testing with subject's main:" << RESET << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << std::endl;
}

void	intDeque(void)
{
	std::cout << BLUE << "Testing with ints and deque:" << RESET << std::endl;

	MutantStack<int>		mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << std::endl;
}

void	stringList(void)
{
	std::cout << BLUE << "Testing with strings and list:" << RESET << std::endl;

	MutantStack<std::string, std::list<std::string> >		mstack;

	mstack.push("Hello");
	mstack.push("World");
	
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << std::endl;
	
	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << std::endl;
}

void	testIterators(void)
{
	std::cout << BLUE << "Testing iterators:" << RESET << std::endl;

	MutantStack<int>		mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(42);
	mstack.push(21);
	mstack.push(0);

	MutantStack<int>::iterator			it = mstack.begin();
	MutantStack<int>::reverse_iterator	reverseit = mstack.rbegin();

	std::cout << "Forward:" << std::endl;
	while (it != mstack.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << "Reverse:" << std::endl;
	while (reverseit != mstack.rend())
	{
		std::cout << *reverseit << std::endl;
		++reverseit;
	}
	std::cout << std::endl;
}

void	testCopy(void)
{
	std::cout << BLUE << "Testing copy:" << RESET << std::endl;

	MutantStack<int>		mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(42);
	mstack.push(21);
	mstack.push(0);

	std::cout << "mstack size: " << mstack.size() << std::endl;
	std::cout << "mstack top: " << mstack.top() << std::endl;
	std::cout << std::endl;

	MutantStack<int>		mstack2(mstack);

	std::cout << "mstack2 size: " << mstack2.size() << std::endl;
	std::cout << "mstack2 top: " << mstack2.top() << std::endl;
	std::cout << std::endl;

	mstack2.pop();

	std::cout << "mstack1 size: " << mstack.size() << std::endl;
	std::cout << "mstack2 size: " << mstack2.size() << std::endl;
	std::cout << std::endl;

	MutantStack<int>		mstack3;

	mstack3 = mstack2;

	std::cout << "mstack3 size: " << mstack3.size() << std::endl;
	std::cout << "mstack3 top: " << mstack3.top() << std::endl;
	std::cout << std::endl;

	mstack3.pop();
	
	std::cout << "mstack1 size: " << mstack.size() << std::endl;
	std::cout << "mstack2 size: " << mstack2.size() << std::endl;
	std::cout << "mstack3 size: " << mstack3.size() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	// subject();

	// intDeque();

	// stringList();

	// testIterators();

	testCopy();

	return (0);
}
