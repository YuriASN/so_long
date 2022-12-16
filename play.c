#include "so_long.h"

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
	while (++i < sol->game->clt_count)
	{
		wx = sol->game->clt[i]->x * 32;
		wy = sol->game->clt[i]->y * 32;
		put_img_transp(sol, sol->clt, wx, wy);
	}
	wx = sol->game->player_pos->x * 32;
	wy = sol->game->player_pos->y * 32;
	put_img_transp(sol, sol->player, wx, wy);
}
