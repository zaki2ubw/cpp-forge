/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:53:22 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 13:15:11 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Logger.hpp"

int main()
{
	{
		Logger::info("START", "Subject requirement test.");
		Animal*	animals[10];
		for (int i = 0; i < 5; ++i)
			animals[i] = new Dog();
		for (int j = 5; j < 10; ++j)
			animals[j] = new Cat();
		for (int k = 0; k < 10; ++k)
			delete animals[k];
		Logger::info("END", "Subject requirement test.");
	}
	{
		Logger::info("START", "Dog Deep Copy test.");
		Dog	corgi;
		corgi.setIdea(0, "Eat tasty beef.");
		Dog	husky(corgi);
		husky.setIdea(0, "Run around grassField.");
		Logger::info("Corgi", std::string("Current idea {") + corgi.getIdea(0) + "}");
		Logger::info("husky", std::string("Current idea {") + husky.getIdea(0) + "}");
		Logger::info("END", "Dog Deep Copy test.");
	}
	{
		Logger::info("START", "Cat Deep Copy test.");
		Cat	ash;
		ash.setIdea(0, "Play with cardBoard.");
		Cat	Maine(ash);
		Maine.setIdea(0, "My tail is Fluffy.");
		Logger::info("ash", std::string("Current idea {") + ash.getIdea(0) + "}");
		Logger::info("Maine", std::string("Current idea {") + Maine.getIdea(0) + "}");
		Logger::info("END", "Cat Deep Copy test.");
	}
	return 0;
}
