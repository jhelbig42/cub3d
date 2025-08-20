/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:43:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 10:16:43 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	tex_init(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx_ptr, game->north.path,
			&game->north.width, &game->north.height);
	game->north.addr = mlx_get_data_addr(game->north.img, &game->north.bpp,
			&game->north.size_line, &game->north.endian);
	game->east.img = mlx_xpm_file_to_image(game->mlx_ptr, game->east.path,
			&game->east.width, &game->east.height);
	game->east.addr = mlx_get_data_addr(game->east.img, &game->east.bpp,
			&game->east.size_line, &game->east.endian);
	game->west.img = mlx_xpm_file_to_image(game->mlx_ptr, game->west.path,
			&game->west.width, &game->west.height);
	game->west.addr = mlx_get_data_addr(game->west.img, &game->west.bpp,
			&game->west.size_line, &game->west.endian);
	game->south.img = mlx_xpm_file_to_image(game->mlx_ptr, game->south.path,
			&game->south.width, &game->south.height);
	game->south.addr = mlx_get_data_addr(game->south.img, &game->south.bpp,
			&game->south.size_line, &game->south.endian);
	if (game->door.path != NULL)
	{
		game->door.img = mlx_xpm_file_to_image(game->mlx_ptr, game->door.path,
				&game->door.width, &game->door.height);
		game->door.addr = mlx_get_data_addr(game->door.img, &game->door.bpp,
				&game->door.size_line, &game->door.endian);
	}
	game->keys0.img = mlx_xpm_file_to_image(game->mlx_ptr, "./displays/keys0.xpm",
			&game->keys0.width, &game->keys0.height);
	game->keys0.addr = mlx_get_data_addr(game->keys0.img, &game->keys0.bpp,
			&game->keys0.size_line, &game->keys0.endian);
	game->keys1.img = mlx_xpm_file_to_image(game->mlx_ptr, "./displays/keys1.xpm",
			&game->keys1.width, &game->keys1.height);
	game->keys1.addr = mlx_get_data_addr(game->keys1.img, &game->keys1.bpp,
			&game->keys1.size_line, &game->keys1.endian);
}

static void	player_init(t_game *game)
{
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
	game->player.dir.x = 0;
	game->player.dir.y = 1;
	game->player.jump_offset = 0;
	game->player.jump_velo = 0;
}

static void	map_init(t_game *game)
{
	game->map.width = 0;
	game->map.height = 0;
}

static bool	mlx_win_img_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (p_err("mlx_init failed"), false);
	game->win_ptr = mlx_new_window(
			game->mlx_ptr, game->width, game->height, "cub3d");
	game->img.img = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	return (true);
}

bool	game_init(t_game *game, char *map_name)
{
	map_init(game);
	player_init(game);
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
	if (!parse_map(game, map_name))
		return (false);
	if (!mlx_win_img_init(game))
		return (false);
	tex_init(game);
	return (true);
}
