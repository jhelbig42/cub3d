/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:43:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 12:13:42 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_game	game_init(void)
{
	static t_game	game;

	game.mlx_ptr = mlx_init();
	game.width = SCREEN_WIDTH;
	game.height = SCREEN_HEIGHT;
	game.win_ptr = mlx_new_window(
			game.mlx_ptr, game.width, game.height, "cub3d");
	game.img.img = mlx_new_image(game.mlx_ptr, game.width, game.height);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel,
			&game.img.line_length, &game.img.endian);
	return (game);
}

t_game	*init_test_game(t_game *game)
{
	int worldMap[5][5] = {
	{1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1},
	};

	game->map.map = (int **)worldMap;
	game->map.width = 5;
	game->map.height = 5;
	game->player = (t_player){ 
		.pos_x = 2,
		.pos_y = 2,
		.dir_x = 1,
		.dir_y = 0
	};
	return (game);
}
