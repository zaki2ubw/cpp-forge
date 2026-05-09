/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 20:32:40 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 22:22:16 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Brain.hpp"

Brain::Brain()
{
	Logger::construct("Brain starts up.");
}

Brain::Brain(const Brain& src)
{
	for (size_t i = 0; i < kIdeaSize; ++i)
		this->ideas[i] = src.ideas[i];
	Logger::construct("Brain starts up by copy.");
}

Brain::~Brain()
{
	Logger::destruct("Brain melt down.");
}

Brain&	Brain::operator=(const Brain& src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < kIdeaSize; ++i)
			this->ideas[i] = src.ideas[i];
	}
	return *this;
}

std::string		Brain::getAnIdea(size_t i) const
{
	if (i < kIdeaSize)
		return ideas[i];
	return "";
}

void			Brain::setAnIdea(size_t i, const std::string& idea)
{
	if (i < kIdeaSize)
		this->ideas[i] = idea;
	return ;
}
