#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.hpp" 

class PhoneBook {

	public :

	PhoneBook(void);
	~PhoneBook(void);

	int		addContact(void);
	int		searchContact(void) const;
	void	printContactList(void) const;

	private :

	Contact	_ContactArray[8];
	int		_ContactCount;
};

#endif
