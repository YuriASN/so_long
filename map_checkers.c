#include "so_long.h"

/*	Check if there's a character that isn't allowed,
	or if it's missing a element.
	Clean quit if error is found or return amount of collectibles */
static int	check_char(char **map, int x, int y)
{
	int	clt;
	int	ep;
	int	xc;

	clt = 0;
	ep = 0;
	while (y > 0)
	{
		--y;
		xc = x;
		while (xc > 0)
		{
			--xc;
			if (map[y][xc] == 'C')
				++clt;
			else if (map[y][xc] == 'E' || map[y][xc] == 'P')
				++ep;
			else if (map[y][xc] != '1' && map[y][xc] != '0' && map[y][xc + 1])
				error_msg(2, map);
		}
	}
	if (clt < 1 || ep != 2)
		error_msg(5, map);
	return (clt);
}

/*	Check if there's wall all around the map
	Clean quit if there isn't */
static void	check_walls(char **map, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[0][++i] && i < x)
		if (map[j][i] != '1')
			error_msg(4, map);
	i = -1;
	while (map[y - 1][++i] && i < x)
		if (map[y -1][i] != '1')
			error_msg(4, map);
	while (map[++j] && j < (y -1))
	{
		if (map[j][0] != '1' || map[j][x - 1] != '1')
			error_msg(4, map);
	}
}

/*	Get position x and y of player in a array. */
static void	get_player(char **map, int *px, int *py)
{
	while (map[++*py + 1])
	{
		*px = 0;
		while (map[*py][++*px + 1])
		{
			if (map[*py][*px] == 'P')
			{
				return ;
			}
		}
	}
}

/*	Run remained map checkers. */
static void	run_checkers(char **map, int x, int y)
{
	int		px;
	int		py;
	int		clt;

	px = 0;
	py = 0;
	check_walls(map, x, y);
	clt = check_char(map, x, y);
	get_player(map, &px, &py);
	check_path(map, clt + 2, px, py);
}

/*	Check if map is correct, give it's size to x and y
	and return maps as char array. */
char	**get_map(int fd, int x, int y)
{
	char	**map;
	int		i;

	i = -1;
	map = ft_calloc(sizeof(char **), y + 1);
	if (!map)
		error_msg(6, NULL);
	map[y] = NULL;
	while (++i < y)
	{
		map[i] = get_next_line(fd);
		if (i < y - 1 && strlen(map[i]) != x + 1)
			error_msg(1, map);
	}
	if (strlen(map[y - 1]) != x)
		error_msg(1, map);
	run_checkers(map, x, y);
	return (map);
}
