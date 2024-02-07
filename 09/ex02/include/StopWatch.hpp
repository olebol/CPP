/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StopWatch.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:24:37 by opelser           #+#    #+#             */
/*   Updated: 2024/02/07 16:16:40 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STOPWATCH_HPP
# define STOPWATCH_HPP

# include <string>
# include <chrono>

class StopWatch
{
	private:
		// Private Attributes
		time_t		_start;
		time_t		_elapsed;
		
	public:
		// Constructors and Destructors
		StopWatch(void);
		StopWatch(const StopWatch &rhs);
		StopWatch &operator=(const StopWatch &rhs);
		~StopWatch(void);

		// Getters
		time_t		getElapsed(void) const;

		// Public Methods
		void		start(void);
		void		stop(void);
} ;

#endif
