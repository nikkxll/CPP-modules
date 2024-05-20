/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:14:08 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 15:43:20 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class	Contact {
	public:
		void	setDetails(const std::string& firstName,
					const std::string& lastName,
					const std::string& nickname,
					const std::string& phoneNumber,
					const std::string& darkestSecret);
		void	displaySummary(int index) const;
		void	displayDetails() const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	
		void	printField(const std::string& field) const;
};

#endif