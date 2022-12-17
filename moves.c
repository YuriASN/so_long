#include "so_long.h"

/*	Changes player image to the given direction and move if isn't a wall. */
void	move_left(t_prog *sol, int x, int y)
{
	put_image(sol, sol->ground, x, y);
	sol->player = sol->plr_left;
	if (sol->map[y][x - 1] == 1)
		return ;
	sol->game->player_pos->x--;
	is_component(sol, --x, y);
}

/*	Changes player image to the given direction and move if isn't a wall. */
void	move_right(t_prog *sol, int x, int y)
{
	put_image(sol, sol->ground, x, y);
	sol->player = sol->plr_right;
	if (sol->map[y][x + 1] == 1)
		return ;
	sol->game->player_pos->x++;
	is_component(sol, ++x, y);
}

/*	Changes player image to the given direction and move if isn't a wall. */
void	move_up(t_prog *sol, int x, int y)
{
	put_image(sol, sol->ground, x, y);
	sol->player = sol->plr_up;
	if (sol->map[y - 1][x] == 1)
		return ;
	sol->game->player_pos->y--;
	is_component(sol, x, --y);
}

/*	Changes player image to the given direction and move if isn't a wall. */
void	move_down(t_prog *sol, int x, int y)
{
	put_image(sol, sol->ground, x, y);
	sol->player = sol->plr_down;
	if (sol->map[y + 1][x] == 1)
		return ;
	sol->game->player_pos->y++;
	is_component(sol, x, ++y);
}
