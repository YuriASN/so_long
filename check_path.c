#include "so_long.h"

/*	If able to move right it changes value of previous position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_right(char **map, int *cmp, int *px, int *py)
{
printf("entrei no move right\t");
	if (map[*py][*px + 1] == '1')
		return (0);
	while (map[*py][*px + 1] != '1')
	{
		if (map[*py][*px] == 'E' || map[*py][*px] == 'C')
			--*cmp;
		if (map[*py][*px] == 'f')
			map[*py][*px] = '1';
		else
			map[*py][*px] = 'f';
		++*px;
	}
	return (1);
}

/*	If able to move left it changes value of previous position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_left(char **map, int *cmp, int *px, int *py)
{
printf("entrei no move left\t");
	if (map[*py][*px -1] == '1')
		return (0);
	while (map[*py][*px -1] != '1')
	{
		if (map[*py][*px] == 'E' || map[*py][*px] == 'C')
			--*cmp;
		if (map[*py][*px] == 'f')
			map[*py][*px] = '1';
		else
			map[*py][*px] = 'f';
		--*px;
	}
	return (1);
}

/*	If able to move up it changes value of previous position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_up(char **map, int *cmp, int *px, int *py)
{
printf("entrei no move up\t");
	if (map[*py -1][*px] == '1')
		return (0);
	while (map[*py -1][*px] != '1')
	{
		if (map[*py][*px] == 'E' || map[*py][*px] == 'C')
			--*cmp;
		if (map[*py][*px] == 'f')
			map[*py][*px] = '1';
		else
			map[*py][*px] = 'f';
		--*py;
	}
	return (1);
}

/*	If able to move down it changes value of previous position.
	Substract 1 if a component (Player, Exit or collectible) are found.
	Return 0 if it's a wall */
static int	move_down(char **map, int *cmp, int *px, int *py)
{
printf("entrei no move down\t");
	if (map[*py + 1][*px] == '1')
		return (0);
	while (map[*py + 1][*px] != '1')
	{
		if (map[*py][*px] == 'E' || map[*py][*px] == 'C')
			--*cmp;
		if (map[*py][*px] == 'f')
			map[*py][*px] = '1';
		else
			map[*py][*px] = 'f';
		++*py;
	}
	return (1);
}

/*	Check if there's available path to collect everything and exit.
	Adds Cmp = collectives plus exit. Player's position are px, py,
	Clean quit if there isn't*/
void	check_path(char **map, int cmp, int px, int py)
{
printf("%sCheck Path%s\t", YEL, CRESET);
	while (map)
	{
printf("entrar no while\n");
		if (!move_right(map, &cmp, &px, &py) &&
		!move_down(map, &cmp, &px, &py) &&
		!move_up(map, &cmp, &px, &py) &&
		!move_left(map, &cmp, &px, &py)	)
			{break;}
int o = -1; printf("\n"); while (map[++o]){printf("%i\t", o);	printf("%s", map[o]);} printf("\n");
printf("\n");
getchar();
	}
	if (cmp != 0)
		error_msg(3, map);
}
