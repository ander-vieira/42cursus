#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
	private:
		std::string fname;
		std::string lname;
		std::string nick;
		std::string phone;
		std::string secret;
	public:
		void initialize(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret);
		void printRow(unsigned int i);
		void printFull();
};

#endif