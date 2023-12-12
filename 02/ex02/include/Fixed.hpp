/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:04 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 22:04:35 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		// Constructors
		Fixed(void);

		Fixed(const int value);
		Fixed(const float value);

		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &rhs);
		~Fixed();

		// Comparison Operators
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		// Arithmetic Operators
		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);

		// Increment and Decrement Operators
		Fixed	&operator++(void);
		Fixed	operator++(int placeholder);
		Fixed	&operator--(void);
		Fixed	operator--(int placeholder);


		// Setters and Getters
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		// Methods
		float	toFloat(void) const;
		int		toInt(void) const;

} ;

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs);


#endif
