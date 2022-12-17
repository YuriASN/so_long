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
//ft_printf("Key code = %i\n", key_code);
	if (key_code == 65361)
		move_left(sol, x, y);
	else if (key_code == 65363)
		move_right(sol, x, y);
	else if (key_code == 65362)
		move_up(sol, x, y);
	else if (key_code == 65364)
		move_down(sol, x, y);
	else if (key_code == 65307)
		end_game(sol);
	put_plr_exit(sol);
}

/*	Handle mouse clicks to close and minimize the window. */
int	close_button(t_prog *sol)
{
printf("chamou pra fechar\n");
	end_game(sol);
}
