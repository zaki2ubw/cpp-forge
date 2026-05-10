/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:50:08 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 16:51:42 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include "IMateriaSource"

class AMateria;

class MateriaSource
{
	public:
		//Constructor&Destructor
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		virtual				~MateriaSource() {};

		//Overlode Operator
		MateriaSource&	operator=(const MateriaSource& src);

		//Functions

		//Virtual Functions
		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
};

