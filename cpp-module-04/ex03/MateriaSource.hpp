/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:27:52 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/02 23:54:37 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
    private:
        static const int _maxMaterias = 4;
        AMateria* _learnedMaterias[_maxMaterias];

    public:
        MateriaSource();
		~MateriaSource() override;
		MateriaSource(const MateriaSource &);
		MateriaSource& operator=(const MateriaSource&);
		
        void learnMateria(AMateria*) override;
        AMateria* createMateria(std::string const & type) override;
};