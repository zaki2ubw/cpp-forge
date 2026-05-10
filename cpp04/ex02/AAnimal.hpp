/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:36:28 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 14:37:25 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class AAnimal
{
	public :
		//Constructor&Destructor
		AAnimal();
		AAnimal(const AAnimal& src);
		virtual ~AAnimal();

		//Overlode Operator
		AAnimal&			operator=(const AAnimal& a);

		//Functions
		std::string		getType() const;

		//Virtual Functions
		virtual void	makeSound() const = 0;

	protected :
		std::string		type;

	private :
};
