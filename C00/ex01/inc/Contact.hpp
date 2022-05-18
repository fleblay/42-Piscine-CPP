#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

	public :

	Contact(void);
	~Contact(void);
	
	void		setInfos(void);
	void		printInfos(void) const;


	private :

	std::string	_Infos[5];

	static const std::string	_Infos_type[5];
};

#endif
