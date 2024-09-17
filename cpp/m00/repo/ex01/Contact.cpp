#include "Contact.hpp"

static void printCapped(std::string text, unsigned int cap)
{
	if (text.length() >= cap)
		std::cout << text.substr(0, cap - 1) << ".";
	else
		std::cout << std::right << std::setw(cap) << text;
}

void Contact::initialize(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret)
{
	this->fname = fname;
	this->lname = lname;
	this->nick = nick;
	this->phone = phone;
	this->secret = secret;
}

void Contact::printRow(unsigned int i)
{
	std::cout << std::right << std::setw(10) << i;
	std::cout <<  "|";
	printCapped(this->fname, 10);
	std::cout <<  "|";
	printCapped(this->lname, 10);
	std::cout <<  "|";
	printCapped(this->nick, 10);
	std::cout <<  "\n";
}

void Contact::printFull()
{
	std::cout << "First name: " << this->fname << "\n";
	std::cout << "Last name: " << this->lname << "\n";
	std::cout << "Nickname: " << this->nick << "\n";
	std::cout << "Phone number: " << this->phone << "\n";
	std::cout << "Darkest secret: " << this->secret << "\n";
}