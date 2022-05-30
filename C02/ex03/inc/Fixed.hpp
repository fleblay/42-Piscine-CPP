#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed {

	public	:

	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);	
	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed & operator=(const Fixed &rhs);
	Fixed	operator+(const	Fixed &rhs) const;
	Fixed	operator-(const	Fixed &rhs) const;
	Fixed	operator*(const	Fixed &rhs) const;
	Fixed	operator/(const	Fixed &rhs) const;

	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed &	operator++(void);
	Fixed &	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed &min(Fixed &lhs, Fixed &rhs);
	static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
	static Fixed &max(Fixed &lhs, Fixed &rhs);
	static const Fixed &max(const Fixed &lhs, const Fixed &rhs);

	private	:

	int					_value;
	static const int	_decimals;
};

std::ostream & operator<<(std::ostream &stream, const Fixed &rhs);

#endif
