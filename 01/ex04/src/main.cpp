/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:26:40 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 16:56:46 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.

// It will open the file <filename> and copies its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.

// Using C file manipulation functions is forbidden and will be considered cheating. All
// the member functions of the class std::string are allowed, except replace. Use them
// wisely!

// Of course, handle unexpected inputs and errors. You have to create and turn in your
// own tests to ensure your program works as expected.

#include <iostream>
#include <fstream>

#include "colors.h"

void	replaceLines(std::ifstream &inputFile, std::ofstream &outputFile, \
			const std::string &toReplace, const std::string &replacementString)
{
	std::string			currentLine;
	while (std::getline(inputFile, currentLine))
	{
		size_t		posFoundString = currentLine.find(toReplace);

		while (posFoundString != std::string::npos)
		{
			currentLine.replace(posFoundString, toReplace.length(), replacementString);
			posFoundString = currentLine.find(toReplace, posFoundString + replacementString.length());
		}
		outputFile << currentLine << "\n";
	}
}

void	mySed(const std::string &inputFileName, const std::string &toReplace, \
			const std::string &replacementString)
{
	// Input validation
	if (inputFileName.empty() || toReplace.empty() || replacementString.empty())
		throw (std::invalid_argument("Arguments can't be empty"));

	// Opening input file
	std::ifstream			inputFile(inputFileName);
	if (!inputFile)
		throw (std::ifstream::failure("Input file" + inputFileName + "failed to open"));

	// Opening output file
	const std::string		outputFileName = inputFileName + ".replace";
	std::ofstream			outputFile(outputFileName);
	if (!outputFile)
	{
		inputFile.close();
		throw (std::ifstream::failure("Output file" + outputFileName + "failed to open"));
	}

	replaceLines(inputFile, outputFile, toReplace, replacementString);
	inputFile.close();
	outputFile.close();
}

int		main(int ac, char **av)
{
	try
	{
		if (ac != 4)
			throw (std::invalid_argument("Incorrect use:\n ./sed [filename] [string to replace] [replacement string]"));
		
		mySed(av[1], av[2], av[3]);
	}
	catch (const std::exception &err)
	{
		std::cerr << C_LRED << C_BOLD << err.what() << C_RESET << std::endl;
		return (1);
	}
	return (0);
}
