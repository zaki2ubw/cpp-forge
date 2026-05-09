/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:42:12 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 18:56:10 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class WrongAnimal
{
	public :
		//Constructor&Destructor
		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		virtual ~WrongAnimal();

		//Overlode Operator
		WrongAnimal&	operator=(const WrongAnimal& a);

		//Functions
		std::string		getType() const;
		void			makeSound() const;

	protected :
		std::string		type;

	private :
};

