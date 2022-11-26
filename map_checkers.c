#include "so_long.h"

/*	Check if there's a character that isn't allowed,
	or if it's missing a element.
	Clean quit if error is found or return amount of collectibles */
static int	check_char(char **map, int x, int y)
{
printf("%sCheck char%s\n", YEL, CRESET);
	int		clt;
	int		ep;
	char	**str;

	str = map;
	clt = 0;
	ep = 0;
	while (*str)
	{
		while (**str)
		{
			if (**str == 'C')
				++clt;
			else if (**str == 'E' || **str == 'P')
				++ep;
			else if (**str != '1' && **str != '0' && str[0][1])
				error_msg(2, str);
			++*str;
		}
		++str;
	}
	if (clt < 1 || ep != 2)
		error_msg(5, str);
	return (clt);
}

/*	Check if there's wall all around the map
	Clean quit if there isn't */
static void	check_walls(char **map, int x, int y)
{
printf("%sCheck Walls%s\n", YEL, CRESET);
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

/*	Check if map is correct, give it's size to x and y
	and return maps as char array */
char	**get_map(int fd, int x, int y)
{

	char	**map;
	int		i;
	int		clt;

printf("x = %i\t y = %i\n", x, y);
	i = -1;
	/* map = ft_calloc(sizeof(char **), (x + 2) * (y + 1));
	if (!map)
		error_msg(6, NULL); */
	map[y] = NULL;
	while (++i < y)
	{
//printf("%i\t", i);
		map[i] = get_next_line(fd);
		if (i < y - 1 && strlen(map[i]) != x + 1){printf("porra emu\n");
			error_msg(1, map);}
//printf("%s", map[i]);
	}
int o = -1;
while (map[++o]){printf("%i\t", o);
	printf("%s", map[o]);}
printf("\n");
	if (strlen(map[y - 1]) != x)
		error_msg(1, map);
	check_walls(map, x, y);
	clt = check_char(map, x, y);
	//check_path(map, clt);
	return (map);
}
