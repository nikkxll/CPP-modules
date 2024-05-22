/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:10:10 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 15:44:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>

class Replacer {
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		std::ifstream inputFile;
		std::ofstream outputFile;

		void setFilename(const std::string& filename);
		void setFirstString(const std::string s1);
		void setSecondString(const std::string s2);
		bool setFiles(const std::string& filename);
		bool ArgsNumberCheck(int argc);
		bool modifyFileContent();
		
	public:
		Replacer();
		int run(int argc, char const *argv[]);
};

#endif