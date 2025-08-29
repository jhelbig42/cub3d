/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:43:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/29 11:33:40 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	player_init(t_game *game)
{
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
	game->player.dir.x = 0;
	game->player.wall_hit = 0;
	game->player.dir.y = 1;
	game->player.jump_offset = 0;
	game->player.jump_velo = 0;
}

static bool	mlx_win_img_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (p_err("mlx_init failed"), false);
	game->win_ptr = mlx_new_window(
			game->mlx_ptr, game->width, game->height, "cub3D");
	if (!game->mlx_ptr)
		return (p_err("mlx_new_window failed"), false);
	game->img.img = mlx_new_image(game->mlx_ptr, game->width, game->height);
	if (!game->img.img)
		return (p_err("mlx_new_image failed"), false);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	return (true);
}

static void	easy_init(t_game *game)
{
	game->map.width = 0;
	game->map.height = 0;
	game->width = SCREEN_WIDTH;
	game->height = SCREEN_HEIGHT;
	game->horizont = SCREEN_HEIGHT * .5;
	game->floor_color = -1;
	game->ceiling_color = -1;
	game->cursor.x = SCREEN_WIDTH * .5;
	game->cursor.y = SCREEN_HEIGHT * .5;
	game->noise = false;
	game->shades = false;
	game->use_mouse = false;
	game->last_frame = get_mills();
	game->len_frame = 1000 / FRAME_RATE;
	game->north.path = NULL;
	game->south.path = NULL;
	game->west.path = NULL;
	game->east.path = NULL;
	game->door.path = NULL;
	game->displays = 0;
}

bool	game_init(t_game *game, char *map_name)
{
	player_init(game);
	easy_init(game);
	if (!parse_map(game, map_name))
		return (false);
	if (!mlx_win_img_init(game))
		return (free_int_arr(game->map.map, game->map.height, game->map.height),
			false);
	if (!tex_init(game))
		return (free_int_arr(game->map.map, game->map.height, game->map.height),
			false);
	return (true);
}
