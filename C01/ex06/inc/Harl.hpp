#ifndef HARL_CLASS_H
# define HARL_CLASS_H

#include <string>

enum {DEFAULT = 0, DEBUG, INFO, WARNING, ERROR};

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

	void	(Harl::*_comment[4])(void);

	static const std::string	_LevelName[4];
};

#endif
