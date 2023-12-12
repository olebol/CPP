/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:17:04 by opelser           #+#    #+#             */
/*   Updated: 2023/12/12 19:29:05 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed		_x;
		const Fixed		_y;

	public:
		// Constructors
		Point(void);

		Point(const float x, const float y);

		Point(const Point &copy);
		Point	&operator=(const Point &rhs);
		~Point();

		// Getters
		float	getX(void) const;
		float	getY(void) const;
} ;

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif
