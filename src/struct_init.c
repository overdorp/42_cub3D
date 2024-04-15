#include "../headers/cub.h"

t_player *player(void)
{
	static t_player player;
	
	return (&player);
}

t_data *data(void)
{
	static t_data   data;
	
	return (&data);
}
