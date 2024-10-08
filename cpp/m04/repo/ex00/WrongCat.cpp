#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &wrongCat): WrongAnimal(wrongCat) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyer called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "woeM" << std::endl;
}