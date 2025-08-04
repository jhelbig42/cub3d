/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:43:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 16:23:53 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	**create_map(void)
{
	int	i;
	int	j;
	int	*line;
	int	**map;

	map = (int **)malloc(sizeof(int *) * 24);
	i = -1;
	while (++i < 24)
	{
		j	= 0;
		line = (int *)malloc(sizeof(int) * 24);
		if (i == 0 || i == 23)
		{
			while (j++ < 23)
				line[j] = 1;
		}
		else
			while (j++ < 23)
				line[j] = 0;
		line[0] = 1;
		line[23] = 1;
		map[i] = line;
	}
	map[3][22] = 1;
	map[3][21] = 1;
	map[3][20] = 1;
	printf("Map Created\n");
	return (map);
}

t_game	game_init(void)
{
	static t_game	game;

	game.mlx_ptr = mlx_init();
	game.width = SCREEN_WIDTH;
	game.height = SCREEN_HEIGHT;
	game.horizont = SCREEN_HEIGHT * .5;
	game.win_ptr = mlx_new_window(
			game.mlx_ptr, game.width, game.height, "cub3d");
	game.img.img = mlx_new_image(game.mlx_ptr, game.width, game.height);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel,
			&game.img.line_length, &game.img.endian);
	return (game);
}

t_game *init_test_game(t_game *game)
{
	game->map.map = create_map();
	game->map.width = 5;
	game->map.height = 5;
	game->player = (t_player){
		.pos.x = 2,
		.pos.y = 2,
		.dir.x = 1,
		.dir.y = 0,
		.walking = 0,
		.rotating = 0,
		.strafing = 0,
		.plane.x = 0,
		.plane.y = 0.66};
	return (game);
}
