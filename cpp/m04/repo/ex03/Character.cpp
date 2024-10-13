#include "Character.hpp"

Character::Character() : name("") {
	for (int i = 0 ; i < Character::SIZE ; i++)
		this->materia[i] = NULL;
}

Character::Character(std::string const name) : name(name) {
	for (int i = 0 ; i < Character::SIZE ; i++)
		this->materia[i] = NULL;
}

Character::Character(Character const &character) : name(character.name) {
	for (int i = 0 ; i < Character::SIZE ; i++) {
		if (character.materia[i] != NULL)
			this->materia[i] = character.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}

Character &Character::operator=(Character const &character) {
	if (this != &character) {
		this->name = character.name;
		for (int i = 0 ; i < Character::SIZE ; i++) {
			delete this->materia[i];
			if (character.materia[i] != NULL)
				this->materia[i] = character.materia[i]->clone();
			else
				this->materia[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0 ; i < Character::SIZE ; i++)
		delete this->materia[i];
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *materia) {
	if (materia == NULL) {
#ifdef DEBUG
		std::cout << "DEBUG: Character " << this->name << " has nothing to equip" << std::endl;
#endif
		return ;
	}
	for (int i = 0 ; i < Character::SIZE ; i++)
		if (this->materia[i] == NULL) {
			this->materia[i] = materia;
#ifdef DEBUG
			std::cout << "DEBUG: Character " << this->name << " equipped " << materia->getType() << " in slot " << i << std::endl;
#endif
			return;
		}
#ifdef DEBUG
	std::cout << "DEBUG: Character " << this->name << " could not equip " << materia->getType() << " because their inventory is full" << std::endl;
#endif
	delete materia;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= Character::SIZE) {
#ifdef DEBUG
		std::cout << "DEBUG: Character " << this->name << " has no inventory slot " << idx << std::endl;
#endif
		return;
	}
	if (this->materia[idx] == NULL) {
#ifdef DEBUG
		std::cout << "DEBUG: Character " << this->name << " has no materia in inventory slot " << idx << std::endl;
#endif
		return;
	}
	delete this->materia[idx];
	this->materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= Character::SIZE) {
#ifdef DEBUG
		std::cout << "DEBUG: Character " << this->name << " has no inventory slot " << idx << std::endl;
#endif
		return;
	}
	if (this->materia[idx] == NULL) {
#ifdef DEBUG
		std::cout << "DEBUG: Character " << this->name << " has no materia in inventory slot " << idx << std::endl;
#endif
		return;
	}
	this->materia[idx]->use(target);
}