/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:29:00 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 16:14:43 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

void testFileReplacement()
{
	Replacer replacer;
	const char* argv[] = {"", "input_1.txt", "School42", "Hive"};

	std::ofstream testFile("input_1.txt");
	if (!testFile.is_open())
	{
		std::cout << "Error: Unable to create the test file" << std::endl;
		return ;
	}
	testFile << "Some information here" << std::endl;
	testFile << "A bit more, this word to change 'School42'" << std::endl;
	testFile << "There should be Hive" << std::endl;
	testFile << "So good that I have this file for a test" << std::endl;

	testFile.close();
	int result = replacer.run(4, argv);
	assert(result == EXIT_SUCCESS);
	std::cout << "Test 1 done successfully" << std::endl;
}

void testFileContentPreservation()
{
	Replacer replacer;
	const char* argv[] = {"program", "input_2.txt", "not_existing", "Hive"};

	std::ofstream testFile("input_2.txt");
	if (!testFile.is_open())
	{
		std::cout << "Error: Unable to create the test file" << std::endl;
		return ;
	}
	testFile << "Some information here" << std::endl;
	testFile << "A bit more, this word to change 'School42'" << std::endl;
	testFile << "There should be School42 since substitution word does not exist" << std::endl;
	testFile << "So good that I have this file for a test" << std::endl;
	int result = replacer.run(4, argv);
	assert(result == EXIT_SUCCESS);
	std::cout << "Test 2 done successfully" << std::endl;
}

void testErrorHandling()
{
	Replacer replacer;
	int argc1 = 1;
	const char* argv1[] = {"./program"};
	
	assert(replacer.run(argc1, argv1) == EXIT_FAILURE);
	std::cout << "Test 3 done successfully" << std::endl;

	int argc2 = 4;
	const char* argv2[] = {"./program", "non_existing_file.txt", "old", "new"};
	
	assert(replacer.run(argc2, argv2) == EXIT_FAILURE);
	std::cout << "Test 4 done successfully" << std::endl;
}

// int main(void)
// {
// 	testFileReplacement();
// 	testFileContentPreservation();
// 	testErrorHandling();
// }

int main(int ac, char const *argv[])
{
	Replacer replacer;
	
	return replacer.run(ac, argv);
}