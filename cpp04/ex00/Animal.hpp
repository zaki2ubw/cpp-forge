/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:49:13 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 18:20:10 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class Animal
{
	public :
		//Constructor&Destructor
		Animal();
		Animal(const Animal& src);
		virtual ~Animal();

		//Overlode Operator
		Animal&			operator=(const Animal& a);

		//Functions
		std::string		getType() const;

		//Virtual Functions
		virtual void	makeSound() const;

	protected :
		std::string		type;

	private :
};
