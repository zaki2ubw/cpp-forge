/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:33:11 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 16:50:30 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class AMateria;

class IMateriaSource
{
	public:
		//Constructor&Destructor
		IMateriaSource();
		IMateriaSource(const IMateriaSource& src);
		virtual				~IMateriaSource() {};

		//Overlode Operator
		IMateriaSource&	operator=(const IMateriaSource& src);

		//Functions

		//Virtual Functions
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

