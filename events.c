#include "so_long.h"

/*	Check wich key was pressed and move player to that direction. */
int	key_press(int key_code, t_prog *sol)
{
	ft_printf("Key code = %i\n", key_code);
	if (key_code == 65361)
		sol->game->moving = 1;
	else if (key_code == 65363)
		sol->game->moving = 2;
	else if (key_code == 65362)
		sol->game->moving = 3;
	else if (key_code == 65364)
		sol->game->moving = 4;
	else if (key_code == 65307)
		finish_prog(sol);
	update(sol);
}

/*	Stop moving the player */
int	key_release(int key_code, t_prog *sol)
{
	if (key_code == 65361 || key_code == 65362
		|| key_code == 65363 || key_code == 65364)
	{
		sol->game->moving = 0;
		ft_printf("key released\n");
	}
	update(sol);
}

/*	Handle mouse clicks to close and minimize the window. */
int	mouse_press(int click, int x, int y, t_prog *sol)
{
	printf("mouse click = %i at %i %i\n", click, x, y);
}
