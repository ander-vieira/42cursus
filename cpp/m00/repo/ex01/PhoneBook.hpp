#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			contacts[8];
		unsigned int	num;
	public:
		PhoneBook();
		void addContact(Contact &contact);
		void printContacts();
		void printDetail(unsigned int i);
};

#endif