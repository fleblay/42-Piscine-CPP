#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

	public :

	Contact(void);
	~Contact(void);
	
	int			setInfos(void);
	void		printInfos(void) const;
	std::string	getInfo(int index)const;

	private :
	std::string	_Infos[5];
	static const std::string	_Infos_type[5];
};

#endif
