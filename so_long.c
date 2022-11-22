#include "so_long.h"

/* Check if file extension is .ber */
static void	check_name(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i - 3] != "." || name[i - 2] != "b"
		|| name[i - 1] != "e" || name[i] != "r")
	{
		perror("Error\nFile isnt a \".ber\" extension.\n");
		exit (0);
	}
}

int	main(char *file_name)
{
	void	*mlx;
	int		x;
	int		y;
	char	**map;
	int		fd;

	check_name(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
		return (0);
	x = 0;
	y = 0;
	map = get_map(fd, &x, &y);


	return (0);
}
