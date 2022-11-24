#include "so_long.h"

/*	Check if there's a character that isn't allowed,
	or if it's missing a element.
	Clean quit if error is found. */
static void	check_char(char **map, int x, int y)
{
	int		c;
	int		ep;
	char	**str;

	str = map;
	c = 0;
	ep = 0;
	while (*str)
	{
		while (**str)
		{
			if (**str == "1" || **str == "0" || **str == "\n")
				continue ;
			else if (**str == "C")
				++c;
			else if (**str == "E" || **str == "P")
				++ep;
			else
				error_msg(2, str);
			++*str;
		}
		++str;
	}
	if (c < 1 || ep != 2)
		error_msg(5, str);
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

/* Get size of map and put if on x and y */
static void	get_size(int fd, int *x, int *y)
{
	char	buffer;

	buffer = 0;
	while (read(fd, &buffer, 1) && buffer != "\n")
		++x;
	if (!buffer)
		error_msg(0, NULL);
	++y;
	while (read(fd, buffer, 1))
		if (buffer == "\n")
			++y;
	if (x <= y || y < 3)
		error_msg(1, NULL);
}

/*	Check if map is correct, give it's size to x and y
	and return maps as char array */
char	**get_map(int fd, int *x, int *y)
{
	char	**str;
	int		i;

	i = 0;
	get_size(fd, &x, &y);
	str = ft_calloc(sizeof(char **), *x + 2);
	if (!str)
		error_msg(6, NULL);
	str[i] = get_next_line(fd);
	while (str[i++])
	{
		str[i] = get_next_line(fd);
		if (strlen(str[i] != *x + 1))
			error_msg(1, str);
	}
	check_walls(str, *x, *y);
	check_char(str, *x, *y);
	check_path(str);
	return (str);
}
