/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:43:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/12 11:08:33 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"


void	tex_init(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx_ptr, game->north.path, &game->north.width, &game->north.height);
	game->north.addr = mlx_get_data_addr(game->north.img, &game->north.bpp,
			&game->north.size_line, &game->north.endian);
	game->east.img = mlx_xpm_file_to_image(game->mlx_ptr, game->east.path, &game->east.width, &game->east.height);
	game->east.addr = mlx_get_data_addr(game->east.img, &game->east.bpp,
			&game->east.size_line, &game->east.endian);
	game->west.img = mlx_xpm_file_to_image(game->mlx_ptr, game->west.path, &game->west.width, &game->west.height);
	game->west.addr = mlx_get_data_addr(game->west.img, &game->west.bpp,
			&game->west.size_line, &game->west.endian);
	game->south.img = mlx_xpm_file_to_image(game->mlx_ptr, game->south.path, &game->south.width, &game->south.height);
	game->south.addr = mlx_get_data_addr(game->south.img, &game->south.bpp,
			&game->south.size_line, &game->south.endian);
}



bool	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (print_error("mlx_init failed"), false);
	game->width = SCREEN_WIDTH;
	game->height = SCREEN_HEIGHT;
	game->horizont = SCREEN_HEIGHT * .5;
	game->win_ptr = mlx_new_window(
			game->mlx_ptr, game->width, game->height, "cub3d");
	game->img.img = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	tex_init(game);
	return (true);
}
