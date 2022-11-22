#include "so_long.h"

/*	Closes the window and print the mandatory "Error\n" message.
	Can be followed by a custom message led by "nbr". */
void	error_msg(int nbr, char **str)
{
	free(str);
	if (nbr == 0)
		perror("Error\nFile has no data.\n");
	if (nbr == 1)
		perror("Error\nFile isnt a \".ber\" extension.\n");
	else if (nbr == 2)
		perror("Error\nMap size isn't correct.\n");
	else if (nbr == 3)
		perror("Error\nNo valid path on the map.\n");
	else if (nbr == 4)
		perror("Error\nMap isn't surrounded by walls.\n");
	else if (nbr == 5)
		perror("Error\nThere isn't a exit point.\n");
	else if (nbr == 6)
		perror("Error\nThere sin't a collectible.\n");
	else if (nbr == 7)
		perror("Error\nThere isn't a starting point.\n");
	else if (nbr == 8)
		perror("Error\nWrong character found.\n");
	exit (0);
}
