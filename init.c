#include "so_long.h"

/*	Initiates positions lists.
	Kill program if error occurs. */
t_pos	*init_pos(t_prog *sol)
{
	t_pos	*init;

	init = ft_calloc(sizeof(t_pos), 1);
	if (!init)
		error_msg("Error\nCouldn't malloc positions.\n", sol);
	init->y = 0;
	init->x = 0;
	return (init);
}

/*	Initiates game struct to 0's.
	Kill program if error occurs. */
static void	game_init(t_prog *sol, char *name)
{
	sol->game = malloc(sizeof(t_game));
	if (!sol->game)
		error_msg("Error\nCouldn't malloc sol->game.\n", sol);
	sol->game->player_pos = 0;
	sol->game->exit = 0;
	sol->game->clt = 0;
	sol->game->go_up = 0;
	sol->game->go_down = 0;
	sol->game->go_left = 0;
	sol->game->go_right = 0;
	sol->game->clt_count = 0;
	sol->game->collected = 0;
	sol->game->move_count = 0;
	get_map(sol, name);
	if (!sol->game->player_pos)
		error_msg("Error\nMap has no player.\n", sol);
	if (!sol->game->exit)
		error_msg("Error\nMap has no exit.\n", sol);
}

/*	Initiates main struct to 0's
	Kill program if error occurs. */
t_prog	*prog_init(char *name)
{
	t_prog	*sol;

	sol = malloc(sizeof(t_prog));
	if (!sol)
		error_msg("Error\nCouldn't malloc sol.\n", sol);
	sol->map = 0;
	sol->game = 0;
	sol->size = init_pos(sol);
	sol->mlx = 0;
	sol->win = 0;
	sol->img = 0;
	sol->player = 0;
	sol->plr_up = 0;
	sol->plr_down = 0;
	sol->plr_left = 0;
	sol->plr_right = 0;
	sol->wall = 0;
	sol->clt = 0;
	sol->ground = 0;
	sol->exit = 0;
	game_init(sol, name);
	game_start(sol);
	return (sol);
}
