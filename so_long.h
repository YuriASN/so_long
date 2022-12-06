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

# include "libft/libft.h"
# include <errno.h>
# include <mlx.h>

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_pos
{
	int			x;
	int			y;
}	t_pos;

typedef struct s_game
{
	t_pos		player_pos;
	t_pos		exit;
	t_pos		*clt;
	int			go_up;
	int			go_down;
	int			go_left;
	int			go_right;
	int			clt_count;
	int			move_count;
}	t_game;

typedef struct s_prog
{
	int			**map;
	t_game		*game;
	t_pos		*size;
	void		*mlx;
	void		*win;
	t_img		*player;
	t_img		*wall;
	t_img		*clt;
	t_img		*ground;
	t_img		*exit;

}	t_prog;

void	error_msg(int nbr, t_prog *sol);
int		open_fd(char *name, t_prog *sol);
t_prog	*prog_init(int fd);
t_pos	*init_pos(t_prog sol);
void	get_map(t_prog sol, char *name);

#endif