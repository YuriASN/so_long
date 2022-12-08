#include "so_long.h"

/*	Render map and calls funtion to render Objects */
static void	start_map(t_prog *sol)
{

}

/*	Start mlx processes, open window and call functions to put images on it. */
int	start_game(t_prog *sol)
{
	sol->mlx = mlx_init();
	if (!sol->mlx)
		error_msg(8, sol);
	sol->win = mlx_new_window(sol->mlx, sol->size->x * 32,
			sol->size->y * 32, "So Long");
	if (!sol->win)
		error_msg(8, sol);
	sol->img = mlx_new_image(sol->mlx, 32, 32);
	if (!sol->img)
		error_msg(8, sol);
	start_map(sol);
}
