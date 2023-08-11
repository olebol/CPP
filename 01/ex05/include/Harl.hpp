/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:04 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 18:35:42 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
	private:
		// Methods
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

	public:
		// Constructors
		Harl(void);
		~Harl();

		// Methods
		void		complain(std::string level);
} ;

#endif
