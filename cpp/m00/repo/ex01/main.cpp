#include "main.hpp"

int main()
{
	PhoneBook		phoneBook;
	std::string		cmd, fname, lname, nick, phone, secret;
	unsigned int	i;

	while (true)
	{
		std::cout << "INPUT COMMAND: ";
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			std::cout << "First name: ";
			std::cin >> fname;
			std::cout << "Last name: ";
			std::cin >> lname;
			std::cout << "Nickname: ";
			std::cin >> nick;
			std::cout << "Phone number: ";
			std::cin >> phone;
			std::cout << "Darkest secret: ";
			std::cin >> secret;
			phoneBook.addContact(fname, lname, nick, phone, secret);
		}
		else if (cmd == "SEARCH" && phoneBook.printContacts())
		{
			std::cout << "PICK ONE: ";
			std::cin >> i;
			if (std::cin.fail())
			{
				std::cout << "NOT A NUMBER\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				phoneBook.printDetail(i);
		}
		else if (cmd == "EXIT")
			break;
	}
}