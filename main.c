#include "headers/cub.h"

void init_player(int x, int y)
{
    while(data()->map[x])
    {
        y = 0;
        while(data()->map[x][y])
        {
            if (data()->map[x][y] == 'N' || data()->map[x][y] == 'S' || data()->map[x][y] == 'E' || data()->map[x][y] == 'W')
            {
                if (data()->map[x][y] == 'N' || data()->map[x][y] == 'S')
                {
                    player()->dirY = 0;
                    player()->dirX = ((data()->map[x][y] == 'N' * -1) + (data()->map[x][y] == 'S'));
                }
                else
                {
                    player()->dirX = 0;
                    player()->dirY = ((data()->map[x][y] == 'W' * -1) + (data()->map[x][y] == 'E'));
                }
                player()->posX = x;    
                player()->posY = y;
            }
        }
        x++;
    }
    player()->planeX = 0;
    player()->planeY = 0.66;
    player()->time = 0;
    player()->oldTime = 0;
}

void    init(char *av, int fd)
{
    data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, screenHeight, screenWidth, "C U B - 3 D");
    data()->mlx_img = mlx_new_image(data()->mlx, screenHeight, screenWidth);
    fd = open(av, O_RDONLY);
	if (fd < 0)
		return;
	data()->map = map_reader(NULL, fd, 0);
	close(fd);
    init_player(0, 0);
}

int	main(int ac, char **av)
{
	(void)ac;
    int x = 0;

    init(av[1], 0);
    
	mlx_loop(data()->mlx);
}