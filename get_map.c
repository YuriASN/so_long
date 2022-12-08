#include "so_long.h"

/*	Get locations of exit, player and collectibles with it's amount. */
static void	get_locations(char c, t_pos *curr, t_prog *sol)
{
	t_pos	new_pos;
	int		i;

	i = -1;
	if (c == '0')
		return ;
	if (c == 'C')
	{
		sol->game->clt[++i] = curr;
	}
	else if (c == 'E')
	{
		if (sol->game->exit->x != 0)
			error_msg(5, sol);
		sol->game->exit = curr;
	}
	else if (c == 'P')
	{
		if (sol->game->player_pos->x != 0)
			error_msg(5, sol);
		sol->game->player_pos = curr;
	}
}

/*	Get Map to array of int while checking for
	player, exit and collectibles locations.
	Also check for not allowed chars. */
static void	fd_to_map(int fd, t_prog *sol)
{
	char	buffer[1];
	t_pos	*curr;

	curr = init_pos(sol);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '1')
			sol->map[curr->y][curr->x] = 1;
		else if (buffer[0] == '\n')
		{
			curr->y++;
			curr->x = -1;
		}
		else if (buffer[0] == '0' || buffer[0] == 'C'
			|| buffer[0] == 'E' || buffer[0] == 'P')
		{
			get_location(buffer[0], curr, sol);
			sol->map[curr->y][curr->x] = 0;
		}
		else
			error_msg(5, sol);
		curr->x++;
	}
	free (curr);
	close (fd);
}

/*	Get size of map and put if on x and y and count collectibles.
	Check if all lines are the same size and if map is a rectangle.
	Kill program if any error is found. */
static void	get_size(int fd, t_prog	*sol)
{
	char	buffer[1];
	int		x;

	while (read(fd, buffer, 1) && buffer[0] != '\n')
		sol->size->x++;
	if (!buffer[0])
		error_msg(0, sol);
	x = 0;
	while (read(fd, buffer, 1))
	{
		++x;
		if (buffer[0] == '\n')
		{
			if (x - 1 != sol->size->x)
				error_msg(1, sol);
			x = 0;
			sol->size->y++;
		}
		if (buffer[0] == 'C')
			sol->game->clt_count++;
	}
	sol->size->y += 2;
	if (sol->size->y < 3 || sol->size->x <= sol->size->y)
		error_msg(1, sol);
	close(fd);
}

/*	Check if map has walls all around.
	Kill program if it doesn't. */
static void	check_walls(t_prog *sol)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (sol->map[0][++i] && i < sol->size->x)
		if (sol->map[j][i] != 1)
			error_msg(4, sol);
	i = -1;
	while (sol->map[sol->size->y - 1][++i] && i < sol->size->x)
		if (sol->map[sol->size->y -1][i] != 1)
			error_msg(4, sol);
	while (sol->map[++j] && j < (sol->size->y -1))
	{
		if (sol->map[j][0] != 1 || sol->map[j][sol->size->x - 1] != 1)
			error_msg(4, sol);
	}
}

/*	Get all map data.
	Kill program if any error is found. */
void	get_map(t_prog *sol, char *name)
{
	int	fd;

	fd = open_fd(name, sol);
	get_size(fd, sol);
	if (sol->game->clt_count < 1)
		error_msg(5, sol);
	sol->map = ft_calloc(sizeof(int), sol->size->y + sol->size->y);
	if (!sol->map)
		error_msg(6, sol);
	fd = open_fd(name, sol);
	fd_to_map(fd, sol);
	check_walls(sol);
}
