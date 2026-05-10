/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:45:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 16:49:18 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		//Constructor&Destructor
		Cure();
		Cure(const Cure& src);
		virtual ~Cure();

		//Overlode Operator
		Cure&	operator=(const Cure& src);

		//Functions

		//Virtual Functions
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

	protected:
};

