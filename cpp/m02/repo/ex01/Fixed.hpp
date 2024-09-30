#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &fixed);
		Fixed(int const i);
		Fixed(float const f);
		Fixed &operator=(Fixed const &fixed);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
	private:
		static int const point = 8;
		int value;
		static int pow2();
};

std::ostream& operator<<(std::ostream& os, Fixed const &fixed);

#endif