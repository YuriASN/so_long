#include "so_long.h"

/*	Remove 1 collectible from the list freeing it's memory */
static void	destroy_collectible(t_prog *sol, int i)
{
	while (i + 1 < sol->game->clt_count - sol->game->collected)
	{
		sol->game->clt[i]->x = sol->game->clt[i + 1]->x;
		sol->game->clt[i]->y = sol->game->clt[i + 1]->y;
		i++;
	}
	sol->game->collected++;
	free(sol->game->clt[i]);
}

/*	If there's an collectible it'll remove it by placing ground on top.
	If htere's a exit and there's nothing else to be collected it exits. */
void	is_component(t_prog *sol, int x, int y)
{
	int	i;

	i = -1;
	while (++i < sol->game->clt_count - sol->game->collected)
	{
		if (sol->game->clt[i]->x == x && sol->game->clt[i]->y == y)
		{
			put_image(sol, sol->ground, x, y);
			destroy_collectible(sol, i);
			return ;
		}
	}
	if (sol->game->exit->x == x && sol->game->exit->y == y
		&& sol->game->clt_count == sol->game->collected)
		end_game(sol);
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
