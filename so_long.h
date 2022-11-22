#ifndef SO_LONG_H
# define SO_LONG_H

# define WHT "\e[0;97m"
# define CYN "\e[0;96m"
# define MAG "\e[0;95m"
# define BLU "\e[0;94m"
# define YEL "\e[0;93m"
# define GRN "\e[0;92m"
# define RED "\e[0;91m"
# define BLK "\e[0;90m"
# define CRESET "\e[0m"

# include <mlx.h>
# include "libft/libft.h"
# include <math.h>
# include <errno.h>

void	error_msg(int nbr, char **str);

void	check_char(char **map, int x, int y);
void	check_path(char **str, int x, int y);
void	check_walls(char **str, int x, int y);
char	**check_map(int fd, int *x, int *y);


#endif