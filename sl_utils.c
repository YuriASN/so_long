#include "so_long.h"

/*	Closes the window and print the mandatory "Error\n" message.
	Can be followed by a custom message led by "nbr". */
void	error_msg(int nbr, char **str)
{
	while (*str)
		free(*str++);
	if (nbr == 0)
		perror("Error\nFile has no data.\n");
	else if (nbr == 1)
		perror("Error\nMap size isn't correct.\n");
	else if (nbr == 2)
		perror("Error\nWrong character found.\n");
	else if (nbr == 3)
		perror("Error\nNo valid path on the map.\n");
	else if (nbr == 4)
		perror("Error\nMap isn't surrounded by walls.\n");
	else if (nbr == 5)
		perror("Error\nThe amount of components on the map are wrong.\n");
	else if (nbr == 6)
		perror("Error\nCouldn't malloc.\n");
	else if (nbr == 7)
		perror("Error\nInvalid number of arguments.\n");
//close windows;
	exit (0);
}
