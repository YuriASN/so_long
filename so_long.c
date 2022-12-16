#include "so_long.h"


/* Check if file extension is .ber */
static void	check_file(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i - 3] != '.' || name[i - 2] != 'b'
		|| name[i - 1] != 'e' || name[i] != 'r')
	{
		perror("Error\nFile isnt a \".ber\" extension.\n");
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_prog	*sol;

	if (argc != 2)
		error_msg("Error\nInvalid number of arguments.", NULL);
	check_file(argv[1]);
	sol = prog_init(argv[1]);
	put_objects(sol);
	mlx_key_hook(sol->win, &key_release, sol);
	mlx_mouse_hook(sol->win, &mouse_press, sol);
	mlx_hook(sol->win, KeyPress, KeyPressMask, &key_press, sol);
	mlx_loop(sol->mlx);
printf("\n\t\t%sExited gracefully%s\n\n", GRN, CRESET);
	exit (0);
}
