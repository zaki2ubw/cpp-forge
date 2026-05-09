/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 20:32:15 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 22:20:10 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>
# include <string>

class Brain
{
	public :
		Brain();
		Brain(const Brain& src);
		~Brain();
		Brain&			operator=(const Brain& b);
		std::string		getAnIdea(size_t i) const;
		void			setAnIdea(size_t i, const std::string& idea);

	private :
		static const size_t	kIdeaSize = 100;
		std::string			ideas[kIdeaSize];
};

