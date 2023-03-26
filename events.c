#include "so_long.h"

/*	Place Player and exit on place */
static void	put_plr_exit(t_prog *sol)
{
	int	wx;
	int	wy;

	wx = sol->game->exit->x * 32;
	wy = sol->game->exit->y * 32;
	put_img_transp(sol, sol->exit, wx, wy);
	wx = sol->game->player_pos->x * 32;
	wy = sol->game->player_pos->y * 32;
	put_img_transp(sol, sol->player, wx, wy);
}

/*	Check wich key was pressed and move player to that direction. */
int	key_press(int key_code, t_prog *sol)
{
	int	x;
	int	y;

	x = sol->game->player_pos->x;
	y = sol->game->player_pos->y;
	if (!sol->start && key_code == 65293)
	{
		sol->start++;
		kill_mlx_img(sol);
		start_map(sol);
		put_objects(sol);
	}
	if (sol->start && key_code == 65361)
		move_left(sol, x, y);
	else if (sol->start && key_code == 65363)
		move_right(sol, x, y);
	else if (sol->start && key_code == 65362)
		move_up(sol, x, y);
	else if (sol->start && key_code == 65364)
		move_down(sol, x, y);
	else if (key_code == 65307)
		end_game(sol);
	if (sol->start)
		put_plr_exit(sol);
	return (1);
}

/*	Handle mouse clicks to close and minimize the window. */
int	close_button(t_prog *sol)
{
	end_game(sol);
	return (1);
}
