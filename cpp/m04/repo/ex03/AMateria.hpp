#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>

class ICharacter;

class AMateria {
	public:
		AMateria(std::string const &type);
		virtual ~AMateria();
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;
	protected:
		std::string const type;
	private:
		AMateria();
		AMateria(AMateria const &aMateria);
		AMateria &operator=(AMateria const &aMateria);
};

# include "ICharacter.hpp"

#endif