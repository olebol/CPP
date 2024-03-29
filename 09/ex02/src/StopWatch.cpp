/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StopWatch.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:26:15 by opelser           #+#    #+#             */
/*   Updated: 2024/02/13 19:40:04 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/StopWatch.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

StopWatch::StopWatch(void)
{
	this->start();
}

StopWatch::StopWatch(const StopWatch &rhs)
{
	*this = rhs;
}

StopWatch &
StopWatch::operator=(const StopWatch &rhs)
{
	if (this != &rhs)
	{
		// Perform deep copy
		this->_start = rhs._start;
	}

	return (*this);
}

StopWatch::~StopWatch(void)
{
}

// ************************************************************************** //
//                                Getters                                     //
// ************************************************************************** //

time_t
StopWatch::getElapsed(void) const
{
	return (this->_elapsed);
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

static time_t
timeInMicroseconds(std::chrono::high_resolution_clock::time_point time)
{
	return (std::chrono::duration_cast<std::chrono::microseconds>(time.time_since_epoch()).count());
}

void
StopWatch::start(void)
{
	_elapsed = 0;

	_start = timeInMicroseconds(std::chrono::high_resolution_clock::now());
}

void
StopWatch::stop(void)
{
	this->_elapsed = timeInMicroseconds(std::chrono::high_resolution_clock::now());

	_elapsed = this->_elapsed - _start;
}
