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
	if (game->clt)
		free(game->clt);
	free (game);
}

/*	Free all malloced inside sol. */
void	finish_prog(t_prog *sol)
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
void	error_msg(char *str, t_prog *sol)
{
	if (str)
		perror(str);
	else
		perror("Error\n");
	if (sol)
		finish_prog(sol);
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
