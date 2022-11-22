#include "so_long.h"

/*	Check if there's a character that isn't allowed,
	or if it's missing a element.
	Clean quit if error is found. */
void	check_char(char **map, int x, int y)
{
	int		c;
	int		e;
	int		p;
	char	**str;

	c = 0;
	e = 0;
	p = 0;
	while (*str)
	{
		while (**str)
		{
			if (**str == "1" || **str == "0" || **str == "\n")
				continue ;
			else if (**str == "C")
				++c;
			else if (**str == "E")
				++e;
			else if (**str == "P")
				++p;
			else
				error_msg(8, str);
			++*str;
		}
		++str;
	}
	if (c < 1 || e != 1 || p != 1)
		error_msg(8, str);
}

/*	Check if there's available path to collect everything and exit 
	Clean quit if there isn't*/
void	check_path(char **str, int x, int y)
{
	error_msg(3, str);
}

/*	Check if there's wall all around the map
	Clean quit if there isn't */
void	check_walls(char **str, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[0][++i] && i < x -1)
		if (str[j][i] != "1")
			error_msg(4, str);
	i = -1;
	while (str[y - 1][++i] && i < x -1)
		if (str[y -1][i] != "1")
			error_msg(4, str);
	while (str[++j] && j < (y -1))
	{
		if (str[j][0] != "1" || str[j][x - 2] != "1")
			error_msg(4, str);
	}
}

/*	Check if map is correct, give it's size to x and y
	and return maps as char array */
char	**check_map(int fd, int *x, int *y)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char **), 10000);
	if (!str)
		return (NULL);
	str[i] = get_next_line(fd);
	if (!str[i])
		error_msg(0, str);
	x = ft_strlen(str[i]);
	while (str[i++])
	{
		str[i] = get_next_line(fd);
		if (strlen(str[i] != x))
			error_msg(2, str);
		++y;
	}
	check_walls(str, x, y);
	check_path(str, x, y);
	if (y < 3)
		error_msg(2, str);
	x -= 1;
	return (str);
}