/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:04:07 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/29 11:18:31 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	orient_init(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx_ptr, game->north.path,
			&game->north.width, &game->north.height);
	game->east.img = mlx_xpm_file_to_image(game->mlx_ptr, game->east.path,
			&game->east.width, &game->east.height);
	game->west.img = mlx_xpm_file_to_image(game->mlx_ptr, game->west.path,
			&game->west.width, &game->west.height);
	game->south.img = mlx_xpm_file_to_image(game->mlx_ptr, game->south.path,
			&game->south.width, &game->south.height);
	if (!game->north.img || !game->east.img 
		|| !game->west.img || !game->south.img)
		return (p_err("tex_init failed"), false);
	game->north.addr = mlx_get_data_addr(game->north.img, &game->north.bpp,
			&game->north.size_line, &game->north.endian);
	game->east.addr = mlx_get_data_addr(game->east.img, &game->east.bpp,
			&game->east.size_line, &game->east.endian);
	game->west.addr = mlx_get_data_addr(game->west.img, &game->west.bpp,
			&game->west.size_line, &game->west.endian);
	game->south.addr = mlx_get_data_addr(game->south.img, &game->south.bpp,
			&game->south.size_line, &game->south.endian);
	return (true);
}

static bool	door_init(t_game *game)
{
	if (game->door.path != NULL)
	{
		game->door.img = mlx_xpm_file_to_image(game->mlx_ptr, game->door.path,
				&game->door.width, &game->door.height);
		if (!game->door.img)
			return (p_err("door tex_init failed"), false);
		game->door.addr = mlx_get_data_addr(game->door.img, &game->door.bpp,
				&game->door.size_line, &game->door.endian);
	}
	return (true);
}

static bool	display_init(t_game *game)
{
	game->keys0.img = mlx_xpm_file_to_image(game->mlx_ptr, KEYS0,
			&game->keys0.width, &game->keys0.height);
	game->keys1.img = mlx_xpm_file_to_image(game->mlx_ptr, KEYS1,
			&game->keys1.width, &game->keys1.height);
	if (!game->keys0.img || !game->keys1.img)
		return (p_err("display_init failed"), false);
	game->keys0.addr = mlx_get_data_addr(game->keys0.img, &game->keys0.bpp,
			&game->keys0.size_line, &game->keys0.endian);
	game->keys1.addr = mlx_get_data_addr(game->keys1.img, &game->keys1.bpp,
			&game->keys1.size_line, &game->keys1.endian);
	return (true);
}

bool	tex_init(t_game *game)
{
	if (!orient_init(game))
		return (false);
	if (!door_init(game))
		return (false);
	if (!display_init(game))
		return (false);
	return (true);
}
