#include "so_long.h"

int	main(int fd)
{
	void	*mlx;
	int		x;
	int		y;
	char	**map;

	if (fd < 3)
		return (0);
	x = 0;
	y = 0;
	map = check_map(fd, &x, &y);


	return (0);
}
