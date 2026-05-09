/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:03:51 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 19:31:44 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		//Constructor&Destructor
		WrongCat();
		WrongCat(const WrongCat& src);
		virtual ~WrongCat();

		//Overlode Operator
		WrongCat&	operator=(const WrongCat& a);
		void		makeSound() const;

	protected :

	private :

};

