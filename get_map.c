#include "so_long.h"

/*	Get locations of exit, player and collectibles with it's amount. */
static void	get_location(char c, t_pos *curr, t_prog *sol)
{
	static int	clt = -1;

	if (c == '0')
		return ;
	if (c == 'C')
	{
		sol->game->clt[++clt]->x = curr->x;
		sol->game->clt[clt]->y = curr->y;
	}
	if ((c == 'E' && sol->game->exit->x)
		|| (c == 'P' && sol->game->player_pos->x))
	{
		free(curr);
		error_msg("Error\nMap has multiple players or exits.\n", sol);
	}
	if (c == 'E')
	{
		sol->game->exit->x = curr->x;
		sol->game->exit->y = curr->y;
	}
	else if (c == 'P')
	{
		sol->game->player_pos->x = curr->x;
		sol->game->player_pos->y = curr->y;
	}
}

/*	Get Map to array of int while checking for
	player, exit and collectibles locations.
	Also check for not allowed chars. */
static void	fd_to_map(int fd, t_prog *sol)
{
	char	buffer;
	t_pos	*curr;

	curr = init_pos(sol);
	while (read(fd, &buffer, 1))
	{
		if (buffer == '1')
			sol->map[curr->y][curr->x] = 1;
		else if (buffer == '\n')
		{
			curr->y++;
			curr->x = -1;
		}
		else if (buffer == '0' || buffer == 'C'
			|| buffer == 'E' || buffer == 'P')
			get_location(buffer, curr, sol);
		else
		{
			free(curr);
			error_msg("Error\nMap has wrong character.\n", sol);
		}
		curr->x++;
	}
	free(curr);
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
	sol->size->y++;
	x = 0;
	while (read(fd, buffer, 1))
	{
		++x;
		if (buffer[0] == '\n')
		{
			if (x - 1 != sol->size->x)
			{
				close(fd);
				error_msg("Error\nMap isn't correct size.\n", sol);
			}
			x = 0;
			sol->size->y++;
		}
		else if (buffer[0] == 'C')
			sol->game->clt_count++;
	}
	if (buffer[0] != '\n')
		sol->size->y++;
}

/*	Check if map has walls all around.
	Kill program if it doesn't. */
static void	checkers(t_prog *sol)
{
	int	i;
	int	j;

	if (sol->game->clt_count < 1)
		error_msg("Error\n Map has no collectibles.\n", sol);
	i = -1;
	j = 0;
	while (sol->map[0][++i] && i < sol->size->x)
		if (sol->map[j][i] != 1)
			error_msg("Error\nMap isn't surrounded by walls.\n", sol);
	i = -1;
	while (sol->map[sol->size->y - 1][++i] && i < sol->size->x)
		if (sol->map[sol->size->y -1][i] != 1)
			error_msg("Error\nMap isn't surrounded by walls.\n", sol);
	while (sol->map[++j] && j < (sol->size->y -1))
	{
		if (sol->map[j][0] != 1 || sol->map[j][sol->size->x - 1] != 1)
			error_msg("Error\nMap isn't surrounded by walls.\n", sol);
	}
	if (!sol->game->exit->x)
		error_msg("Error\nMap has no exit.\n", sol);
	if (!sol->game->player_pos->x)
		error_msg("Error\nMap has no player.\n", sol);
}

/*	Get all map data.
	Kill program if any error is found. */
void	get_map(t_prog *sol, char *name)
{
	int	fd;
	int	i;

	i = -1;
	fd = open_fd(name, sol);
	get_size(fd, sol);
	close(fd);
	sol->map = ft_calloc(sizeof(int *), sol->size->y);
	if (!sol->map)
		error_msg("Error\nFailed to malloc sol->map line amount.", sol);
	while (++i < sol->size->y)
	{
		sol->map[i] = ft_calloc(sizeof(int *), sol->size->x);
		if (!sol->map[i])
			error_msg("Error\nFailed to malloc map line data.", sol);
	}
	sol->game->clt = ft_calloc(sizeof(t_pos *), sol->game->clt_count);
	i = -1;
	while (++i < sol->game->clt_count)
		sol->game->clt[i] = init_pos(sol);
	fd = open_fd(name, sol);
	fd_to_map(fd, sol);
	checkers(sol);
	fd = open_fd(name, sol);
	check_path(sol, fd);
}
