#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
	private:
		std::string fname;
		std::string lname;
		std::string nick;
		std::string phone;
		std::string secret;
	public:
		Contact(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret);
		void printLine();
		void printFull();
};

#endif