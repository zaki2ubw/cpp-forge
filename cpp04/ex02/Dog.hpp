/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:27:46 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 14:39:57 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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

		//Functions
		std::string		getIdea(size_t i) const;
		void			setIdea(size_t i, const std::string& idea);

	protected :

	private :
		Brain*	brain_;
};

