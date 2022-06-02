#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

# include <string>

# define BLUE "\x1b[34m"
# define RESET "\x1b[0m"

class Brain
{
	public	:	

	Brain(void);
	Brain(const Brain &src);
	Brain(const std::string &thought);
	~Brain(void);

	const std::string	*getIdeas(void) const;
	void				setIdeas(const std::string &thought);

	Brain	&operator=(const Brain &rhs);

	private	:

	std::string	_ideas[100];
};

#endif
