#ifndef CUB_H
# define CUB_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "get_next_line.h"
# include <stdio.h>

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

typedef struct s_data
{
	void	*mlx;
	void	*win;
    char    **map;
	t_img	*mlx_img;
}t_data;

typedef struct s_player
{
	double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double time; //time of current frame
    double oldTime; //time of previous frame
	t_img	*img;
}t_player;


//structs
t_player *player(void);
t_data *data(void);

//map
char    **map_reader(char **map, int fd, int counter);

#endif