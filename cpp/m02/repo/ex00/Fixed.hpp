#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &fixed);
		Fixed &operator=(Fixed const &fixed);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
	private:
		static int const point = 8;
		int value;
};

#endif