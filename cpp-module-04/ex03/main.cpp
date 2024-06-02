/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:01:00 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/03 00:44:07 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
        std::cout << "----- PDF testing -----" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
        std::cout << "----- PDF testing is over -----" << std::endl << std::endl;
    }
    {
        std::cout << "----- Simulation testing -----" << std::endl;
        IMateriaSource* new_src = new MateriaSource();
        new_src->learnMateria(new Ice());
        AMateria* new_tmp = new_src->createMateria("fake_ice");
        new_tmp = new_src->createMateria("ice");
        ICharacter* hero = new Character("hero");
        hero->equip(new_tmp);
        new_src->createMateria("cure");
        new_src->learnMateria(new Cure());
        new_src->learnMateria(new Cure());
        new_src->learnMateria(new Cure());
        new_src->learnMateria(new Ice());
        for (int i = 0; i < 2; i++)
            hero->equip(new_src->createMateria("cure"));
        ICharacter* enemy = new Character("enemy");
        hero->use(0, *enemy);
        hero->use(1, *enemy);
        hero->use(2, *enemy);
        hero->use(3, *enemy);
        hero->use(-100, *enemy);
        hero->use(1000000000, *enemy);
        std::cout << std::endl;

        std::cout << "----- Deep copy testing -----" << std::endl;

        Character* charles = new Character("Charles");
        charles->equip(new_src->createMateria("cure"));
        charles->equip(new_src->createMateria("ice"));
        charles->equip(new_src->createMateria("earth"));
        charles->equip(new_src->createMateria("ice"));
        Character* charles_copy = new Character(*charles);
        std::cout << std::endl;
        
        charles_copy->equip(new_src->createMateria("cure"));

        std::cout << std::endl;
        charles->use(0, *enemy);
        charles->use(1, *enemy);
        charles->use(2, *enemy);
        charles->use(3, *enemy);
        std::cout << std::endl;
        charles_copy->use(0, *enemy);
        charles_copy->use(1, *enemy);
        charles_copy->use(2, *enemy);
        charles_copy->use(3, *enemy);
        std::cout << std::endl;

        charles->unequip(-1);
        charles->unequip(18);

        charles->use(1, *charles);
        charles->unequip(1);
        charles->use(1, *charles);

        *charles_copy = *charles;
        charles->unequip(0);
        charles->unequip(1);
        charles_copy->unequip(2);
        charles_copy->unequip(3);

        std::cout << std::endl;
        charles->use(0, *enemy);
        charles->use(1, *enemy);
        charles->use(2, *enemy);
        charles->use(3, *enemy);
        std::cout << std::endl;
        charles_copy->use(0, *enemy);
        charles_copy->use(1, *enemy);
        charles_copy->use(2, *enemy);
        charles_copy->use(3, *enemy);
        std::cout << std::endl;

        delete enemy;
        delete hero;
        delete new_src;
        delete charles;
	    delete charles_copy;
        std::cout << "----- Own testing is over -----" << std::endl << std::endl;
    }
    
    return EXIT_SUCCESS;
}