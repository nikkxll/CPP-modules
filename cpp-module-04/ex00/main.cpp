/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:36:35 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/29 16:31:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "---Animal instance created---" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "Animal type: " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;
	std::cout << std::endl;
	
	std::cout << "---Animal instance created---" << std::endl;
	const Animal* j = new Dog();
	std::cout << "Animal type: " << j->getType() << std::endl;
	j->makeSound();
	delete j;
	std::cout << std::endl;
	
	std::cout << "---Animal instance created---" << std::endl;
	const Animal* i = new Cat();
	std::cout << "Animal type: " << j->getType() << std::endl;
	i->makeSound();
	delete i;
	std::cout << std::endl;

	std::cout << "---WrongAnimal instance created---" << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	std::cout << "WrongAnimal type: " << wrong->getType() << std::endl;
	wrong->makeSound();
	delete wrong;
	std::cout << std::endl;
	
	std::cout << "---WrongAnimal instance created---" << std::endl;
	const WrongAnimal* k = new WrongCat();
	std::cout << "WrongAnimal type: " << k->getType() << std::endl;
	k->makeSound();
	delete k;
	std::cout << std::endl;

	return 0;
}
