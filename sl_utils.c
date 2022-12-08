#include "so_long.h"

/*	Free all malloc inside game */
static void	finish_game(t_game *game)
{
	if (game->player_pos)
		free (game->player_pos);
	if (game->exit)
		free (game->exit);
	while (game->clt_count--)
		free (game->clt[game->clt_count]);
	free (game);
}

/*	Free all malloced inside sol. */
static void	finish_prog(t_prog *sol)
{
	if (!sol)
		return ;
	if (sol->game)
		finish_game(sol->game);
	if (sol->size)
		free (sol->size);
	if (sol->map)
		free (sol->map);
	free (sol);
}

/*	Closes the window and print the mandatory "Error\n" message.
	Can be followed by a custom message led by "nbr". */
void	error_msg(int nbr, t_prog *sol)
{
	if (sol)
		finish_prog(sol);
	if (nbr == 0)
		perror("Error\nInvalid file.\n");
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
	else if (nbr == 8)
		perror("Error\nSomething went wrong with MLX!\n");
	exit (0);
}

/*	Return opened file or end program if can't open. */
int	open_fd(char *name, t_prog *sol)
{
	int	fd;

	if (!name)
		error_msg(0, sol);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		error_msg(0, sol);
	return (fd);
}
