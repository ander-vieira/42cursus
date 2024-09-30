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
		bool operator>(Fixed const &fixed) const;
		bool operator<(Fixed const &fixed) const;
		bool operator>=(Fixed const &fixed) const;
		bool operator<=(Fixed const &fixed) const;
		bool operator==(Fixed const &fixed) const;
		bool operator!=(Fixed const &fixed) const;
		Fixed operator+(Fixed const &fixed) const;
		Fixed operator-(Fixed const &fixed) const;
		Fixed operator*(Fixed const &fixed) const;
		Fixed operator/(Fixed const &fixed) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static Fixed const &max(Fixed const &f1, Fixed const &f2);
		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed const &min(Fixed const &f1, Fixed const &f2);
	private:
		static int const point = 8;
		int value;
		static int pow2();
};

std::ostream& operator<<(std::ostream& os, Fixed const &fixed);

#endif