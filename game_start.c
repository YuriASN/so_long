#include "so_long.h"

/*	Render walls and empty spaces. */
void	start_map(t_prog *sol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < sol->size->y)
	{
		x = -1;
		while (++x < sol->size->x)
		{
			if (sol->map[y][x] == 1)
				put_image(sol, sol->wall, x, y);
			else if (sol->map[y][x] == 0)
				put_image(sol, sol->ground, x, y);
		}
	}
}

/*	Attribute image files to it's pointers. */
static void	get_images(t_prog *sol, int w, int h)
{
	sol->plr_up = mlx_xpm_file_to_image(sol->mlx, "img/plr_b.xpm", &w, &h);
	if (!sol->plr_up)
		error_msg("Error\nCouldn't load image plr_b.xpm\n", sol);
	sol->plr_down = mlx_xpm_file_to_image(sol->mlx, "img/plr_f.xpm", &w, &h);
	if (!sol->plr_down)
		error_msg("Error\nCouldn't load image plr_f.xpm\n", sol);
	sol->plr_left = mlx_xpm_file_to_image(sol->mlx, "img/plr_l.xpm", &w, &h);
	if (!sol->plr_left)
		error_msg("Error\nCouldn't load image plr_l.xpm\n", sol);
	sol->plr_right = mlx_xpm_file_to_image(sol->mlx, "img/plr_r.xpm", &w, &h);
	if (!sol->plr_right)
		error_msg("Error\nCouldn't load image plr_r.xpm\n", sol);
	sol->wall = mlx_xpm_file_to_image(sol->mlx, "img/wall.xpm", &w, &h);
	if (!sol->wall)
		error_msg("Error\nCouldn't load image wall.xpm\n", sol);
	sol->clt = mlx_xpm_file_to_image(sol->mlx, "img/collect.xpm", &w, &h);
	if (!sol->clt)
		error_msg("Error\nCouldn't load image collect.xpm\n", sol);
	sol->ground = mlx_xpm_file_to_image(sol->mlx, "img/floor.xpm", &w, &h);
	if (!sol->ground)
		error_msg("Error\nCouldn't load image floor.xpm\n", sol);
	sol->exit = mlx_xpm_file_to_image(sol->mlx, "img/exit.xpm", &w, &h);
	if (!sol->exit)
		error_msg("Error\nCouldn't load image exit.xpm\n", sol);
	sol->player = sol->plr_down;
}

/*	Start mlx processes, open window and call functions to put images on it. */
void	game_start(t_prog *sol)
{
	int	w;
	int	h;

	if (sol->mlx)
		return ;
	sol->mlx = mlx_init();
	if (!sol->mlx)
		error_msg("Error\nCouldn't initialize mlx.\n", sol);
	sol->win = mlx_new_window(sol->mlx, sol->size->x * 32,
			sol->size->y * 32, "So Long");
	if (!sol->win)
		error_msg("Error\nCouldn't initialize window.\n", sol);
	sol->img = mlx_new_image(sol->mlx, 32, 32);
	if (!sol->img)
		error_msg("Error\nCouldn't initialize mlx image.\n", sol);
	get_images(sol, w, h);
}
