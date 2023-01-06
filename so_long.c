#include "so_long.h"

/*	Return opened file or end program if can't open. */
int	open_fd(char *name, t_prog *sol)
{
	int	fd;

	if (!name)
		error_msg(0, sol);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		error_msg(0, sol);
	return (fd);
}

/* Check if file extension is .ber
	And if there's data on the file.*/
static void	check_file(char *name)
{
	int		i;
	int		fd;
	char	buffer[1];

	i = ft_strlen(name) - 1;
	if (name[i - 3] != '.' || name[i - 2] != 'b'
		|| name[i - 1] != 'e' || name[i] != 'r')
	{
		perror("Error\nFile isnt a \".ber\" extension.\n");
		exit (0);
	}
	fd = open_fd(name, NULL);
	if (!read(fd, buffer, 1))
	{
		close(fd);
		perror("Error\nFile has no data.\n");
		exit(0);
	}
	close (fd);
}

int	main(int argc, char **argv)
{
	t_prog	*sol;

	if (argc != 2)
		error_msg("Error\nInvalid number of arguments.\n", NULL);
	check_file(argv[1]);
	sol = prog_init(argv[1]);
	mlx_string_put(sol->mlx, sol->win, 1, 32, 13107250,
		"Press\"ENTER\"");
	put_mlx_img(sol);
	mlx_hook(sol->win, KeyPress, KeyPressMask, &key_press, sol);
	mlx_hook(sol->mlx, DestroyNotify, StructureNotifyMask, &close_button, sol);
	mlx_loop(sol->mlx);
	exit (0);
}
