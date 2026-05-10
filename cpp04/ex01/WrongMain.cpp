/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongMain.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:07:14 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 13:44:11 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"
#include "Logger.hpp"

int main()
{
	Logger::info("START", "WrongCat Shallow Copy test.");
	WrongCat	ash;
	ash.setIdea(0, "Play with cardBoard.");
	WrongCat	Maine(ash);
	Maine.setIdea(0, "My tail is Fluffy.");
	Logger::info("ash", std::string("Current idea {") + ash.getIdea(0) + "}");
	Logger::info("Maine", std::string("Current idea {") + Maine.getIdea(0) + "}");
	Logger::info("END", "WrongCat Shallow Copy test.");
	return 1;
}
