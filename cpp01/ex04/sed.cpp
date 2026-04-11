/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:36:19 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/10 16:02:57 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string	sedSingleLine(
		const std::string& line, const std::string& tgt, const std::string& rep)
{
	size_t	i = 0;
	std::string	result;

	if (tgt.empty())
		return line;
	if (line.size() < tgt.size())
		return line;
	size_t	lineLen = line.size();
	size_t	tgtLen = tgt.size();

	while (i < lineLen)
	{
		if (line[i] == tgt[0] && tgtLen <= lineLen - i)
		{
			std::string check = line.substr(i, tgtLen);
			if (check == tgt)
			{
				result += rep;
				i += tgtLen;
			}
			else
			{
				result += line[i];
				++i;
			}
		}
		else
		{
			result += line[i];
			++i;
		}
	}
	return result;
}
