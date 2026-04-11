/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 13:36:35 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 17:17:50 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Harl
{
	public :
		Harl();
		~Harl();
		void	complain(const std::string& level);

	private :
		static void	debug(void);
		static void	info(void);
		static void	warning(void);
		static void	error(void);
};
