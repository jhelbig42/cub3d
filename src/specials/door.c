#include "door.h"

void	open_door(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;

	if (game->map.map[y + 1][x] == 2)
		game->map.map[y + 1][x] = 0;
	else if (game->map.map[y - 1][x] == 2)
		game->map.map[y - 1][x] = 0;
	else if (game->map.map[y][x + 1] == 2)
		game->map.map[y][x + 1] = 0;
	else if (game->map.map[y][x - 1] == 2)
		game->map.map[y][x - 1] = 0;
}