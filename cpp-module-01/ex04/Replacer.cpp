/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:10:13 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 15:45:29 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer()
{
}

void Replacer::setFilename(const std::string &filename)
{
	this->filename = filename;
}

void Replacer::setFirstString(const std::string s1)
{
	this->s1 = s1;
}

void Replacer::setSecondString(const std::string s2)
{
	this->s2 = s2;
}

bool Replacer::setFiles(const std::string &filename)
{
	inputFile.open(filename);
	if (!inputFile)
	{
		std::cout << "Unable to open file for reading" << std::endl;
		return false;
	}
	outputFile.open(filename + ".replace");
	if (!outputFile)
	{
		std::cout << "Unable to open output file for writing" << std::endl;
		inputFile.close();
		return false;
	}
	return true;
}

bool Replacer::ArgsNumberCheck(int argc)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return false;
	}
	return true;
}

bool Replacer::modifyFileContent()
{
	std::string line;
	size_t j = 0;

	if (this->setFiles(filename) == false)
		return false;
	while (std::getline(inputFile, line))
	{
		for (size_t i = 0; line[i] != '\0'; i++)
		{
			j = 0;
			if (line[i] == s1[j]
				&& std::strncmp(&line[i], &s1[j], s1.length()) == 0)
			{
				while (j < s2.length())
					outputFile.put(s2[j++]);
				i += s1.length() - 1;
				continue;
			}
			outputFile.put(line[i]);
		}
		outputFile.put('\n');
	}
	inputFile.close();
	return true;
}

int Replacer::run(int argc, char const *argv[])
{
	if (this->ArgsNumberCheck(argc) == false)
		return EXIT_FAILURE;
	this->setFilename(argv[1]);
	this->setFirstString(argv[2]);
	this->setSecondString(argv[3]);
	if (this->modifyFileContent() == false)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
