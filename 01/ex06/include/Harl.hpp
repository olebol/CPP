/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:04 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 20:34:51 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#define C_LRED		"\x1b[38;2;255;128;128m"
#define C_LBLUE		"\x1b[38;2;128;128;255m"
#define C_LGREEN	"\x1b[38;2;128;255;128m"
#define C_LYELLOW	"\x1b[38;2;255;255;128m"

#define C_RESET		"\x1b[0m"
#define C_BOLD		"\x1b[1m"

#include <string>

enum eLevel
{
	debug,
	info,
	warning,
	error,
	insignificant
} ;

class Harl
{
	private:
		eLevel	_filter;

		// Methods
		void		_debug(void);
		void		_info(void);
		void		_warning(void);
		void		_error(void);

	public:
		// Constructors
		Harl(const std::string &filter);
		Harl(void);
		~Harl();

		// Setters
		void		setFilter(const std::string &newFilter);

		// Getters
		eLevel	getFilter(void) const;

		// Methods
		void		complain(const std::string &level);
} ;

#endif
