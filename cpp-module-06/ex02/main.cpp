/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/07 13:13:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	Base* obj = generate();
	
	std::cout << "passing pointer to the obj, trying to define the real type\n";
	std::cout << "Real type is:";
	identify(obj);

	std::cout << "passing reference to the obj, trying to define the real type\n";
	std::cout << "Real type is:";
	identify(*obj);
	
	delete obj;

	return 0;
}
