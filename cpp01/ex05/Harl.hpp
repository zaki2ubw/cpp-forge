/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 13:36:35 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 14:04:40 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Harl
{
	public :
		Harl();
		~Harl();
		void	complain(std::string level);

	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};
