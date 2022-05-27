#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed {

	public	:

	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);	

	Fixed & operator=(const Fixed &rhs);

	private	:

	int					_value;
	static const int	_decimals;
};

#endif
