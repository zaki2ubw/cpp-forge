/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:40:38 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 16:53:21 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
		//Constructor&Destructor
		Ice();
		Ice(const Ice& src);
		virtual ~Ice();

		//Overlode Operator
		Ice&	operator=(const Ice& src);

		//Functions

		//Virtual Functions
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

	protected:
};
