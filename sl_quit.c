#include "so_long.h"

/*	Free all malloc inside game */
static void	finish_game(t_game *game)
{
	int	i;

	if (game->player_pos)
		free(game->player_pos);
	if (game->exit)
		free(game->exit);
	i = -1;
	if (game->clt)
		while (++i < game->clt_count - game->collected)
			free(game->clt[i]);
	if (game->clt)
		free(game->clt);
	free(game);
}

/*	Free all malloced inside sol. */
void	finish_prog(t_prog *sol)
{
	int	i;

	if (!sol)
		return ;
	if (sol->game)
		finish_game(sol->game);
	if (sol->win)
		mlx_destroy_window(sol->mlx, sol->win);
	if (sol->mlx)
		mlx_destroy_display(sol->mlx);
	i = -1;
	if (sol->map)
	{
		if (sol->map[0])
			while (++i < sol->size->y)
				free(sol->map[i]);
		free(sol->map);
	}
	if (sol->size)
		free(sol->size);
	free(sol);
}

/*	Finish the mlx process and call finish prog */
int	end_game(t_prog *sol)
{
	if (sol->plr_up)
		mlx_destroy_image(sol->mlx, sol->plr_up);
	if (sol->plr_down)
		mlx_destroy_image(sol->mlx, sol->plr_down);
	if (sol->plr_left)
		mlx_destroy_image(sol->mlx, sol->plr_left);
	if (sol->plr_right)
		mlx_destroy_image(sol->mlx, sol->plr_right);
	if (sol->wall)
		mlx_destroy_image(sol->mlx, sol->wall);
	if (sol->ground)
		mlx_destroy_image(sol->mlx, sol->ground);
	if (sol->clt)
		mlx_destroy_image(sol->mlx, sol->clt);
	if (sol->exit)
		mlx_destroy_image(sol->mlx, sol->exit);
	if (sol->img)
		mlx_destroy_image(sol->mlx, sol->img);
	finish_prog(sol);
	exit (0);
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
		end_game(sol);
	exit (0);
}
