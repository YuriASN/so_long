#include "so_long.h"

/*	If able to move right it changes value of previous position.
	Substract 1 of it's repectives int if a collectible, player or exit is found.
	Return 0 if it's a wall */
static int	move_right(char **map, int *clt, int *ep)
{
	if (map[0][1] != '1')
	{
		if (map[0][0] == 'P' || map[0][0] == 'E')
			--*ep;
		else if (map[0][0] == 'C')
			--*clt;
		if (map[0][0] == 'f')
			map[0][0] = '1';
		else
			map[0][0] = 'f';
		return (1);
	}
	return (0);
}

/*	If able to move left it changes value of previous position.
	Substract 1 of it's repectives int if a collectible, player or exit is found.
	Return 0 if it's a wall */
static int	move_left(char **map, int *clt, int *ep)
{
	if (map[0][-1] != '1')
	{
		if (map[0][0] == 'P' || map[0][0] == 'E')
			--*ep;
		else if (map[0][0] == 'C')
			--*clt;
		if (map[0][0] == 'f')
			map[0][0] = '1';
		else
			map[0][0] = 'f';
		return (1);
	}
	return (0);
}

/*	If able to move up it changes value of previous position.
	Substract 1 of it's repectives int if a collectible, player or exit is found.
	Return 0 if it's a wall */
static int	move_up(char **map, int *clt, int *ep)
{
	if (map[-1][0] != '1')
	{
		if (map[0][0] == 'P' || map[0][0] == 'E')
			--*ep;
		else if (map[0][0] == 'C')
			--*clt;
		if (map[0][0] == 'f')
			map[0][0] = '1';
		else
			map[0][0] = 'f';
		return (1);
	}
	return (0);
}

/*	If able to move down it changes value of previous position.
	Substract 1 of it's repectives int if a collectible, player or exit is found.
	Return 0 if it's a wall */
static int	move_down(char **map, int *clt, int *ep)
{
	if (map[1][0] != '1')
	{
		if (map[0][0] == 'P' || map[0][0] == 'E')
			--*ep;
		else if (map[0][0] == 'C')
			--*clt;
		if (map[0][0] == 'f')
			map[0][0] = '1';
		else
			map[0][0] = 'f';
		return (1);
	}
	return (0);
}

/*	Check if there's available path to collect everything and exit 
	Clean quit if there isn't*/
void	check_path(char **map, int clt)
{
	int	x;
	int	y;
	int	ep;

	x = 1;
	y = 1;
	ep = 2;
	while (map)
	{
		if (move_right(&(&map[x])[y], &clt, &ep))
			x += 1;
		else if (move_down(&(&map[x])[y], &clt, &ep))
			y += 1;
		else if (move_left(&(&map[x])[y], &clt, &ep))
			x -= 1;
		else if (move_up(&(&map[x])[y], &clt, &ep))
			y -= 1;
		else
			break ;
	}
	if (clt != 0 || ep != 0)
		error_msg(3, map);
}
