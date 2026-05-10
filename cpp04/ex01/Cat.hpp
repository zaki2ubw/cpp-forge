/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:36:19 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 12:31:11 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :
		//Constructor&Destructor
		Cat();
		Cat(const Cat& src);
		virtual ~Cat();

		//Overlode Operator
		Cat&			operator=(const Cat& a);

		//Virtual Functions
		virtual void	makeSound() const;

		//Functions
		std::string		getIdea(size_t i) const;
		void			setIdea(size_t i, const std::string& idea);

	protected :

	private :
		Brain*	brain_;
};

