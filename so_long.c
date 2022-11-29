#include "so_long.h"

/* Get size of map and put if on x and y */
static void	get_size(int fd, int *x, int *y)
{
	char	buffer[1];

	buffer[0] = 0;
	while (read(fd, buffer, 1) && buffer[0] != '\n')
		++*x;
	if (!buffer[0])
		error_msg(0, NULL);
	++*y;
	while (read(fd, buffer, 1))
		if (buffer[0] == '\n')
			++*y;
	++*y;
	if (*x <= *y || *y < 3)
		error_msg(1, NULL);
	close(fd);
}

/* Check if file extension is .ber */
static void	check_name(char *name)
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
	void	*mlx;
	char	**map;
	int		x;
	int		y;
	int		fd;

	x = 0;
	y = 0;
	if (argc != 2)
		error_msg(7, NULL);
	check_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (0);
	get_size(fd, &x, &y);
	fd = open(argv[1], O_RDONLY);
	map = get_map(fd, x, y);
int o = -1;printf("fim do main\n"); while (map[++o]){printf("%i\t", o);	printf("%s", map[o]);} printf("\n");
while(*map)
	free(*map++);
//int o = -1; while (map[++o]){printf("%i\t", o); printf("%s", map[o]);}
printf("\n\t\t%sExited gracefully%s\n\n", GRN, CRESET);
	exit (0);
}
