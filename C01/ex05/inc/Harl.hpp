#ifndef HARL_CLASS_H
# define HARL_CLASS_H

#include <string>

class Harl {

	public	:

	Harl(void);
	~Harl(void);

	void	complain(std::string level);

	private	:

	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);

	void	(*_comment[4])(void);
};

#endif
