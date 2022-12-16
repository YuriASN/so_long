#include "so_long.h"

/*	Changes player image to left and move if isn't a wall. */
static void	move_left(t_prog *sol, int x, int y)
{
	sol->player = sol->plr_left;
	if (sol->map[y][x - 1] == 1)
		return ;
	sol->game->player_pos->x--;
	put_image(sol, sol->ground, x, y);
//	is_component(sol, --x, y);
}

static void	move_right(t_prog *sol, int x, int y)
{
	sol->player = sol->plr_right;
	if (sol->map[y][x + 1] == 1)
		return ;
	sol->game->player_pos->x++;
	put_image(sol, sol->ground, x, y);
//	is_component(sol, ++x, y);
}

static void	move_up(t_prog *sol, int x, int y)
{
	sol->player = sol->plr_up;
	if (sol->map[y - 1][x] == 1)
		return ;
	sol->game->player_pos->y--;
	put_image(sol, sol->ground, x, y);
//	is_component(sol, x, --y);
}

static void	move_down(t_prog *sol, int x, int y)
{
	sol->player = sol->plr_down;
	if (sol->map[y + 1][x] == 1)
		return ;
	sol->game->player_pos->y++;
	put_image(sol, sol->ground, x, y);
//	is_component(sol, x, ++y);
}

/*	Move if key is being pressed */
void	update(t_prog *sol)
{
	int	x;
	int	y;

	x = sol->game->player_pos->x;
	y = sol->game->player_pos->y;
	if (sol->game->moving == 0)
		return ;
	else if (sol->game->moving == 1)
		move_left(sol, x, y);
	else if (sol->game->moving == 2)
		move_right(sol, x, y);
	else if (sol->game->moving == 3)
		move_up(sol, x, y);
	else if (sol->game->moving == 4)
		move_down(sol, x, y);
	put_objects(sol);
}
