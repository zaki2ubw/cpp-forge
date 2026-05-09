/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:27:46 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 22:03:21 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public :
		//Constructor&Destructor
		Dog();
		Dog(const Dog& src);
		virtual ~Dog();

		//Overlode Operator
		Dog&			operator=(const Dog& a);

		//Virtual Functions
		virtual void	makeSound() const;

	protected :

	private :
		Brain*	brain_;
};

