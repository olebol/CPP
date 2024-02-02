/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:11 by opelser           #+#    #+#             */
/*   Updated: 2024/02/02 17:44:38 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>

# include <map>

class BitcoinExchange
{
	private:
		// Private Attributes
		std::map<std::string, double>		_exchangeRates;

	public:
		// Constructors and Destructors
		BitcoinExchange(void);
		BitcoinExchange(std::string &filename);
		BitcoinExchange(const BitcoinExchange &rhs);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange(void);

		// Exceptions
		class NoRateAvailable : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("No rate available for this date");
				}
		};

		class invalidValue : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Entered value is not between 0 and 1000");
				}
		};

		// Adding rates
		void		addRate(std::string date, double rate);
		void		parseData(std::string &filename);

		// Public Methods
		double		getRate(std::string &date) const;
		double		exchange(std::string &date, double amount) const;
} ;


#endif
