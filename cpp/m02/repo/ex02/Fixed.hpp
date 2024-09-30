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
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
	private:
		const static int point = 8;
		int value;
		static int pow2();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif