#include "so_long.h"

/*	If able to move right it changes value of next position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_right(char **map, int *cmp, int *px, int *py)
{
printf("Move RIGHT\t");
	if (map[*py][*px + 1] == '1' || map[*py][*px + 1] == 'X')
		return (0);
	if (map[*py][*px + 1] != '1' && map[*py][*px + 1] != 'X')
	{
		if (map[*py][*px + 1] == 'E' || map[*py][*px + 1] == 'C')
			--*cmp;
		/* if (map[*py][*px + 1] == 'B')
			map[*py][*px + 1] = 'X';
		else */
		map[*py][*px + 1] = 'B';
		++*px;
	}
	return (1);
}

/*	If able to move left it changes value of next position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_left(char **map, int *cmp, int *px, int *py)
{
printf("Move LEFT\t");
	if (map[*py][*px -1] == '1' || map[*py][*px -1] == 'X')
		return (0);
	if (map[*py][*px -1] != '1' && map[*py][*px -1] != 'X')
	{
		if (map[*py][*px -1] == 'E' || map[*py][*px -1] == 'C')
			--*cmp;
		/* if (map[*py][*px -1] == 'B')
			map[*py][*px -1] = 'X';
		else */
		map[*py][*px -1] = 'B';
		--*px;
	}
	return (1);
}

/*	If able to move up it changes value of next position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_up(char **map, int *cmp, int *px, int *py)
{
printf("Move UP\t");
	if (map[*py -1][*px] == '1' || map[*py -1][*px] == 'X')
		return (0);
	if (map[*py -1][*px] != '1' && map[*py -1][*px] != 'X')
	{
		if (map[*py -1][*px] == 'E' || map[*py -1][*px] == 'C')
			--*cmp;
		/* if (map[*py -1][*px] == 'B')
			map[*py -1][*px] = 'X';
		else */
		map[*py -1][*px] = 'B';
		--*py;
	}
	return (1);
}

/*	If able to move down it changes value of next position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_down(char **map, int *cmp, int *px, int *py)
{
printf("Move DOWN\t");
	if (map[*py + 1][*px] == '1'  || map[*py + 1][*px] == 'X')
		return (0);
	if (map[*py + 1][*px] != '1' && map[*py + 1][*px] != 'X')
	{
		if (map[*py + 1][*px] == 'E' || map[*py + 1][*px] == 'C')
			--*cmp;
		/* if (map[*py + 1][*px] == 'B')
			map[*py + 1][*px] = 'X';
		else */
		map[*py + 1][*px] = 'B';
		++*py;
	}
	return (1);
}

/*	Check if there's available path to collect everything and exit.
	Adds Cmp = collectives plus exit. Player's position are px, py,
	Clean quit if there isn't*/
void	check_path(char **map, int cmp, int px, int py)
{
	int	last;

	last = 0;
printf("%sCheck Path%s\t", YEL, CRESET);
	map[py][px] = 'B';
	while (map)
	{
int o = -1; printf("\n"); while (map[++o]){printf("%i\t", o);	printf("%s", map[o]);} printf("\n"); getchar();
printf("%sentrar no while%s", RED, CRESET);

		/* if (move_right(map, &cmp, &px, &py))
			continue ;
		if (move_down(map, &cmp, &px, &py))
			continue ;
		if (move_left(map, &cmp, &px, &py))
			continue ;
		if (move_up(map, &cmp, &px, &py))
			continue ; */
		/* if (last == 0)
			if (!move_right(map, &cmp, &px, &py))
				last = 1;
		if (last == 1)
			if (!move_down(map, &cmp, &px, &py))
				last = 2;
		if (last == 2 )
			if (!move_left(map, &cmp, &px, &py))
				last = 3;
		if (last == 3)
			if (!move_up(map, &cmp, &px, &py))
				last = 0; */
/* if (!move_right(map, &cmp, &px, &py) &&
!move_down(map, &cmp, &px, &py) &&
!move_up(map, &cmp, &px, &py) &&
!move_left(map, &cmp, &px, &py)	)
	{break;} */
//int o = -1; printf("\n"); while (map[++o]){printf("%i\t", o);	printf("%s", map[o]);} printf("\n");
printf("\n");
getchar();
//		break ;
	}
	if (cmp != 0)
		error_msg(3, map);
}
