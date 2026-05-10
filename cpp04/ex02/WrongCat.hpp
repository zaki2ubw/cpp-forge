/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:03:51 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 13:37:24 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	public :
		//Constructor&Destructor
		WrongCat();
		WrongCat(const WrongCat& src);
		virtual ~WrongCat();

		//Overlode Operator
		WrongCat&	operator=(const WrongCat& a);

		//Functions
		void		makeSound() const;
		std::string	getIdea(size_t i) const;
		void		setIdea(size_t i, const std::string& idea);

	protected :

	private :
		Brain*	brain_;
};

