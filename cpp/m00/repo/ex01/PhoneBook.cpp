#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->num = 0;
}

void PhoneBook::addContact(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret)
{
	this->contacts[this->num % 8].initialize(fname, lname, nick, phone, secret);
	this->num += 1;
}
bool PhoneBook::printContacts()
{
	if (this->num == 0)
	{
		std::cout << "NOTHING TO SEARCH\n";
		return false;
	}
	for (unsigned int i = 0 ; i < 8 && i < this->num ; i++)
		this->contacts[i].printRow(i);
	return true;
}
void PhoneBook::printDetail(unsigned int i)
{
	if (i >= 8 || i >= this->num)
	{
		std::cout << "WRONG NUMBER\n";
		return;
	}
	this->contacts[i % 8].printFull();
}
