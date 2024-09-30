#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int i);
		Fixed(const float f);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
	private:
		const static int point = 8;
		int value;
		static int pow2();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif