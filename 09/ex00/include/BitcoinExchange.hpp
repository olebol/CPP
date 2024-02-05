/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:11 by opelser           #+#    #+#             */
/*   Updated: 2024/02/05 20:04:44 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>

# include <map>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

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

		class InvalidDate : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Entered date is invalid");
				}
		};

		class InvalidValue : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Entered value is invalid");
				}
		};

		class NegativeValue : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Entered value is negative");
				}
		};

		class ValueTooHigh : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return ("Entered value is too high");
				}
		};


		// Adding rates
		void		addRate(std::string date, double rate);
		void		parseData(std::string &filename);

		// Public Methods
		double		getRate(std::string &date) const;
		double		exchange(std::string &date, double amount) const;

		// Static Methods
		static std::string		convertToDate(const std::string &input);
		static double			convertToRate(const std::string &input, const size_t start);
} ;


#endif
