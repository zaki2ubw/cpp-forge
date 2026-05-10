/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:47:37 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 16:52:18 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	public:
		//Constructor&Destructor
		Character();
		Character(const Character& src);
		virtual ~Character() {}

		//Overlode Operator
		Character&	operator=(const Character& src);

		//Functions

		//Virtual Functions
		virtual std::string	const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
};

