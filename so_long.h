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
# include <mlx_int.h>

typedef struct s_pos
{
	int			x;
	int			y;
}	t_pos;

typedef struct s_game
{
	t_pos		*player_pos;
	t_pos		*exit;
	t_pos		**clt;
	int			go_up;
	int			go_down;
	int			go_left;
	int			go_right;
	int			clt_count;
	int			collected;
	int			move_count;
	int			moving;
}	t_game;

typedef struct s_prog
{
	int			**map;
	t_game		*game;
	t_pos		*size;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_img		*player;
	t_img		*plr_up;
	t_img		*plr_down;
	t_img		*plr_left;
	t_img		*plr_right;
	t_img		*wall;
	t_img		*clt;
	t_img		*ground;
	t_img		*exit;

}	t_prog;

void	error_msg(char *str, t_prog *sol);
int		open_fd(char *name, t_prog *sol);
t_prog	*prog_init(char *name);
t_pos	*init_pos(t_prog *sol);
void	game_start(t_prog *sol);
void	finish_prog(t_prog *sol);
void	get_map(t_prog *sol, char *name);
void	put_img_transp(t_prog *sol, t_img *img, int wx, int wy);
void	put_image(t_prog *sol, t_img *img, int x, int y);
int		key_press(int key_code, t_prog *sol);
int		close_button(t_prog *sol);
void	put_objects(t_prog *sol);
void	is_component(t_prog *sol, int x, int y);
void	move_right(t_prog *sol, int x, int y);
void	move_left(t_prog *sol, int x, int y);
void	move_up(t_prog *sol, int x, int y);
void	move_down(t_prog *sol, int x, int y);
int		end_game(t_prog *sol);

#endif