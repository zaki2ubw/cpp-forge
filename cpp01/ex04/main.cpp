/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:03:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 09:28:03 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <fstream>

int	main(int argc, char **argv)
{
	std::string		line;
	std::string		inputFileName;
	std::string		replacedFileName;
	std::string		searchWord;
	std::string		replaceWord;

	if (argc != 4)
	{
		std::cout << "[USAGE]: ./miniSed fileName searchWord replaceWord";
		std::cout << std::endl;
		return 1;
	}
	inputFileName = static_cast<std::string>(argv[1]);
	searchWord = static_cast<std::string>(argv[2]);
	replaceWord = static_cast<std::string>(argv[3]);
	std::ifstream	inFile(inputFileName);
	if (!inFile)
	{
		std::cerr << "[ERROR]: InputFile couldn't open." << std::endl;
		return 1;
	}
	replacedFileName = inputFileName + ".replace";
	std::ofstream	outFile(replacedFileName);
	if (!outFile)
	{
		std::cerr << "[ERROR]: OutputFile couldn't open." << std::endl;
		return perror("ofstream"), 1;
	}
	while (std::getline(inFile, line))
	{
		outFile << sedSingleLine(line, searchWord, replaceWord);
		outFile << "\n";
	}
	return 0;
}
