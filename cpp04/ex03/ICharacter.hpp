/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:30:22 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 16:13:33 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class AMateria;

class ICharacter
{
	public:
		//Constructor&Destructor
		ICharacter();
		ICharacter(const ICharacter& src);
		virtual ~ICharacter() {}

		//Overlode Operator
		ICharacter&	operator=(const ICharacter& src);

		//Functions

		//Virtual Functions
		virtual std::string	const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
