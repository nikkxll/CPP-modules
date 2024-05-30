/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:36:35 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/30 16:16:19 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	{
		std::cout << "\033[33m" << "exercise example\n"<< "\033[0m";
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << std::endl;

		delete j;//should not create a leak
		delete i;
		std::cout << std::endl;
	}
	{
		Animal* animal_arr[4];
		
		for (int i = 0; i < 4; ++i)
		{
			if (i < 2)
				animal_arr[i] = new Dog();
			else
				animal_arr[i] = new Cat();
		}

		std::cout << std::endl;
		
		animal_arr[0]->setIdea(0, "What a life to be a dog!");
		animal_arr[1]->setIdea(0, "What a life to be a dog!");
		animal_arr[2]->setIdea(0, "What a life to be a cat!");
		animal_arr[3]->setIdea(0, "What a life to be a cat!");

		std::cout << animal_arr[0]->getType() << std::endl;
		std::cout << animal_arr[0]->getIdea(0) << std::endl;
		std::cout << animal_arr[1]->getType() << std::endl;
		std::cout << animal_arr[1]->getIdea(0) << std::endl;
		std::cout << animal_arr[2]->getType() << std::endl;
		std::cout << animal_arr[2]->getIdea(0) << std::endl;
		std::cout << animal_arr[3]->getType() << std::endl;
		std::cout << animal_arr[3]->getIdea(0) << std::endl;
		
		std::cout << std::endl;
		
// std::cout << std::endl;

// 	{
// 		std::cout << "\033[33m" << "Deep Copy Test Cat Copy\n"<< "\033[0m";
// 		Cat cat;
// 		Cat copy_cat(cat);
		
// 		std::cout << std::endl;

// 		std::cout << "This is idea 10 from cat: " << cat.getIdea(10) << std::endl;
// 		cat.setIdea(10, "This is the new idea to paint the moon");
// 		std::cout << "This is the new idea 10 from cat: " << cat.getIdea(10) << std::endl;

// 		std::cout << "This is idea 10 from copy_cat: " << copy_cat.getIdea(10) << std::endl;

// 		std::cout << std::endl;
// 	}
	
// 	std::cout << std::endl;


// 	{
// 		std::cout << "\033[33m" << "Deep Copy Test Dog Assignment\n"<< "\033[0m";
// 		Dog dog;
// 		Dog assignment_dog(dog);
// 		std::cout << std::endl;
		
// 		std::cout << "This is idea 10 from dog: " << dog.getIdea(10) << std::endl;
// 		dog.setIdea(10, "This is the new idea to paint the moon");
// 		std::cout << "This is the new idea 10 from dog: " << dog.getIdea(10) << std::endl;
// 		std::cout << std::endl;

// 		std::cout << "This is idea 10 from assignment_dog before assignment: " << assignment_dog.getIdea(10) << std::endl;
// 		assignment_dog = dog;
// 		std::cout << "This is idea 10 from assignment_dog after assignment: " << assignment_dog.getIdea(10) << std::endl;
// 		std::cout << std::endl;

// 		assignment_dog.setIdea(10, "Better paint the mars!");
// 		std::cout << "This is the new idea 10 from assignment dog: " << assignment_dog.getIdea(10) << std::endl;
// 		std::cout << "This is idea 10 from dog: " << dog.getIdea(10) << std::endl;

// 		std::cout << std::endl;
// 	}

		for (Animal* animal : animal_arr)
			delete animal;

		std::cout << std::endl;
	}
}