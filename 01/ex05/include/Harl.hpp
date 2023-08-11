/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:04 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 20:42:08 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

#define C_LRED		"\x1b[38;2;255;128;128m"
#define C_LBLUE		"\x1b[38;2;128;128;255m"
#define C_LGREEN	"\x1b[38;2;128;255;128m"
#define C_LYELLOW	"\x1b[38;2;255;255;128m"

#define C_RESET		"\x1b[0m"
#define C_BOLD		"\x1b[1m"

class Harl
{
	private:
		// Methods
		void		_debug(void);
		void		_info(void);
		void		_warning(void);
		void		_error(void);

	public:
		// Constructors
		Harl(void);
		~Harl();

		// Methods
		void		complain(std::string level);
} ;

#endif
