#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			contacts[8];
		unsigned int	num;
	public:
		PhoneBook();
		void addContact(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret);
		bool printContacts();
		void printDetail(unsigned int i);
};

#endif