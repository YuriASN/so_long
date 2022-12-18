#include "so_long.h"

/* Return color of pixel as a unsigned int. */
static unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

/* 	Check if pixel of image is transparent.
	Return TRUE or FALSE */
static int	is_transp(t_img *img, int x, int y)
{
	if (!(img->data + (x * img->bpp / 8 + y * img->size_line))[0])
		return (1);
	return (0);
}

/* Put image without backgorund on ~window's~ coordenates wx and wy. */
void	put_img_transp(t_prog *sol, t_img *img, int wx, int wy)
{
	int				y;
	int				x;
	unsigned int	color;

	y = -1;
	while (++y <= img->height)
	{
		x = -1;
		while (++x <= img->width)
		{
			color = mlx_get_pixel(img, x, y);
			if (!is_transp(img, x, y))
				mlx_pixel_put(sol->mlx, sol->win, x + wx, y + wy, color);
		}
	}
}

/*	Put images on ~map's~ coordenates x and y. */
void	put_image(t_prog *sol, t_img *img, int x, int y)
{
	mlx_put_image_to_window(sol->mlx, sol->win, img, x * 32, y * 32);
}

/*	Place Player, exit and collectibles on place. */
void	put_objects(t_prog *sol)
{
	int	i;
	int	wx;
	int	wy;

	wx = sol->game->exit->x * 32;
	wy = sol->game->exit->y * 32;
	put_img_transp(sol, sol->exit, wx, wy);
	i = -1;
	while (++i < sol->game->clt_count - sol->game->collected)
	{
		wx = sol->game->clt[i]->x * 32;
		wy = sol->game->clt[i]->y * 32;
		put_img_transp(sol, sol->clt, wx, wy);
	}
	wx = sol->game->player_pos->x * 32;
	wy = sol->game->player_pos->y * 32;
	put_img_transp(sol, sol->player, wx, wy);
}
