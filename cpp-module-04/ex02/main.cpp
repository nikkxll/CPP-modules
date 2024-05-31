/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:36:35 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/31 11:57:46 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	// will throw an error if uncomment it
	// const AAnimal* err = new AAnimal();
	
	{
		std::cout << "\033[33m" << "exercise example\n"<< "\033[0m";
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		
		std::cout << std::endl;

		delete j;//should not create a leak
		delete i;
		std::cout << std::endl;
	}
	{
		AAnimal* animal_arr[4];
		
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

		std::cout << "------Deep copy test------\n" << std::endl;
		Cat cat;
		Cat deep_copy_cat(cat);
		
		for (int j = 0; j < 100; ++j)
			cat.setIdea(j, "Cat Idea " + std::to_string(j + 1));
		for (int j = 0; j < 100; ++j)
			deep_copy_cat.setIdea(j, "Cat DeepIdea " + std::to_string(j + 1));
		
		std::cout << std::endl;

		std::cout << "This is idea 10 from cat: " << cat.getIdea(9) << std::endl;
		cat.setIdea(9, "This is the new idea, oh wow");
		std::cout << "This is the new idea 10 from cat: " << cat.getIdea(9) << std::endl;

		std::cout << "This is idea 10 from copy_cat: " << deep_copy_cat.getIdea(9) << std::endl;

		std::cout << std::endl;

		std::cout << "------Deep copy assignment test------\n" << std::endl;
		Dog dog;
		Dog deep_copy_dog(dog);
		std::cout << std::endl;
		
		for (int j = 0; j < 100; ++j)
			dog.setIdea(j, "Dog Idea " + std::to_string(j + 1));
		for (int j = 0; j < 100; ++j)
			deep_copy_dog.setIdea(j, "Dog DeepIdea " + std::to_string(j + 1));

		std::cout << "This is idea 10 from dog: " << dog.getIdea(9) << std::endl;
		dog.setIdea(9, "This is the new future shared idea, woof");
		std::cout << "This is the new idea 10 from dog: " << dog.getIdea(9) << std::endl;
		std::cout << std::endl;

		std::cout << "This is idea 10 from deep_copy_dog before assignment: " << deep_copy_dog.getIdea(9) << std::endl;
		deep_copy_dog = dog;
		std::cout << "This is idea 10 from deep_copy_dog after assignment: " << deep_copy_dog.getIdea(9) << std::endl;
		std::cout << std::endl;

		deep_copy_dog.setIdea(9, "This idea is actually better");
		std::cout << "This is the new idea 10 from deep_copy_dog dog: " << deep_copy_dog.getIdea(9) << std::endl;
		std::cout << "This is idea 10 from dog: " << dog.getIdea(9) << std::endl;

		std::cout << std::endl;

		for (AAnimal* animal : animal_arr)
			delete animal;

		std::cout << std::endl;
	}
}