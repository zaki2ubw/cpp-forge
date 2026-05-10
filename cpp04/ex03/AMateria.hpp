/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:20:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 16:17:09 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class ICharacter;

class AMateria
{
	public:
		//Constructor&Destructor
		AMateria();
		AMateria(const AMateria& src);
		AMateria(std::string const & type);
		virtual ~AMateria();

		//Overlode Operator
		AMateria&	operator=(const AMateria& src);

		//Functions
		std::string const&	getType() const;

		//Virtual Functions
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	type;
};
