#include "Harl.hpp"

int	main(void)
{
	Harl	Harlito;

	Harlito.complain("DEBUG");
	Harlito.complain("INFO");
	Harlito.complain("WARNING");
	Harlito.complain("ERROR");
	Harlito.complain("NOT_A_REAL_LEVEL");
	return (0);
}
