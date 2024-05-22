/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:57:03 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/21 13:19:09 by dnikifor         ###   ########.fr       */
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
		PhoneBook();
		void	start();
		
	private:
		Contact	contacts[MAX_CONTACTS];
		int		_count;
		int		_nextIndex;
		
		void	addContact();
		void	searchContacts() const;
		void	printMessage(std::string message) const;
		void	printErrorMessage(std::string message) const;
};

#endif