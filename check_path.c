#include "so_long.h"

/* Changes the value of place about to leave
	Return 1 if it's a collectible.*/
static int	trace_move(char c)
{
	if (c == "f")
		c = "1";
	else if (c == "P" || c == "0")
		c = "f";
	else if (c == "C")
	{
		c = "f";
		return (-1);
	}
	return (0);
}

/* Moves to the next place until finds exit-
	Return 1 if moved or 0 if already moved everywhere */
static void	move_everywhere(char **str, int c)
{
	//muda valor primeiro (collectible += trace_move) e move depois.
		//Se a casa da direita for != 1 move.
		//Se nao for tenta para baixo, cima e por fim esquerda.
}

//Return the amount of collectibles on the map.
static int	get_collectibles(char **map, int c)
{

}

/*	Check if there's available path to collect everything and exit 
	Clean quit if there isn't*/
void	check_path(char **str, int x, int y)
{
	int	c;

	c = get_collectibles;
	move_everywhere(&str[1][1], c);
	error_msg(3, str);
}
