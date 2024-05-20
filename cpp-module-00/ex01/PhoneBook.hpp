/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:57:03 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 14:47:12 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define ORANGE "\e[38;5;208m"
# define EC "\x1B[0m"

class	PhoneBook {
	public:
		PhoneBook() : count(0), nextIndex(0) {}

		void	start();
		
	private:
		Contact	contacts[MAX_CONTACTS];
		int		count;
		int		nextIndex;
		
		void	addContact();
		void	searchContacts() const;
		void	printMessage(std::string message, std::string color) const;
};

#endif