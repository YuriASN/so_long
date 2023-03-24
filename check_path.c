
#include "so_long.h"

/*	Reads fd file to a char array */
static char	**fd_to_char(t_prog *sol, int fd)
{
	char	**map;
	char	*buffer;
	int		i;

	buffer = ft_calloc(sizeof(char *), sol->size->x + 2);
	map = ft_calloc(sizeof(char **), sol->size->y + 1);
	i = -1;
	while (read(fd, buffer, sol->size->x + 1))
	{
		map[++i] = ft_calloc(sizeof(char *), sol->size->x + 1);
		ft_strlcpy(map[i], buffer, sol->size->x + 1);
	}
	free(buffer);
	close(fd);
	return (map);
}

/*	Go around player initial position changing places where already been.
	Collectibles are reduced when found and exit reduces it as well.
	If path is valid the clts must end with -1.*/
static void	walk_around(char **map, int x, int y, int *clts)
{
	if (map[y][x] == '1' || map[y][x] == 'o')
		return ;
	if (map[y][x] == 'E')
	{
		*clts -= 1;
		map[y][x] = 'o';
	}
	else if (map[y][x] == 'C')
	{
		*clts -= 1;
		map[y][x] = 'o';
	}
	else if (map[y][x] == 'P')
		map[y][x] = 'o';
	else if (map[y][x] == '0')
		map[y][x] = 'o';
	walk_around(map, x + 1, y, clts);
	walk_around(map, x - 1, y, clts);
	walk_around(map, x, y + 1, clts);
	walk_around(map, x, y - 1, clts);
}

/*	Check if there's a available path on the map to
	collect all itens and exit.*/
void	check_path(t_prog *sol, int fd)
{
	char	**map;
	int		x;
	int		y;
	int		clts;
	int		i;

	map = fd_to_char(sol, fd);
	x = sol->game->player_pos->x;
	y = sol->game->player_pos->y;
	clts = sol->game->clt_count;
	walk_around(map, x, y, &clts);
	i = -1;
	while (++i <= sol->size->y)
		free (map[i]);
	free (map);
	if (clts != -1)
		error_msg("Error\nMap has no valid path\n", sol);
}
