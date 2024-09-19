#ifndef FIXED_H
# define FIXED_H

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits();
		void setRawBits(int const raw);
	private:
		const static int	point = 8;
		int					value;
};

#endif