/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:14:08 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 14:39:36 by dnikifor         ###   ########.fr       */
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
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	
		void	printField(const std::string& field) const;
};

#endif