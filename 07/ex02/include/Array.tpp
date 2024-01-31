/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:40:43 by opelser           #+#    #+#             */
/*   Updated: 2024/01/31 20:19:36 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

template <typename T>
Array<T>::Array(void)
	: _size(0), _array(new T[0]())
{
	std::cout << GREEN << "Array: Default constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const unsigned int n)
	:	_size(n), _array(new T[n]())
{
	std::cout << GREEN << "Array: Parametric constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &rhs)
{
	std::cout << GREEN << "Array: Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs)
{
	std::cout << GREEN << "Array: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
		this->_size = rhs._size;

		this->_array = new T[rhs._size];
		for (size_t i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._array[i];
	}

	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] (this->_array);

	std::cout << RED << "Array: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                            Operator Overload                               //
// ************************************************************************** //

template <typename T>
T	&Array<T>::operator[](const unsigned int i) const
{
	if (i >= this->_size)
		throw (std::runtime_error("Index out of range"));
	return (this->_array[i]);
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}
