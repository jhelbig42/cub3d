/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:43:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/07 10:15:40 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	player_init(t_game *game)
{
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
	game->player.dir.x = 0;
	game->player.dir.y = 1;
	game->player.jump_offset = 0;
}

static void	map_init(t_game *game)
{
	game->map.width = 0;
	game->map.height = 0;
}

static void	mlx_win_img_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(
			game->mlx_ptr, game->width, game->height, "cub3d");
	game->img.img = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
}

t_game	game_init(t_game game)
{
	map_init(&game);
	player_init(&game);
	game.width = SCREEN_WIDTH;
	game.height = SCREEN_HEIGHT;
	game.horizont = SCREEN_HEIGHT * .5;
	game.floor_color = -1;
	game.ceiling_color = -1;
	game.north_path = NULL;
	game.south_path = NULL;
	game.west_path = NULL;
	game.east_path = NULL;
	game.noise = false;
	game.shades = false;
	game.last_frame = get_mills();
	game.len_frame = 1000 / FRAME_RATE;
	mlx_win_img_init(&game);
	return (game);
}
