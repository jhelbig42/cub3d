/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:43:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/06 14:17:40 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

/*
t_game	tex_init(t_game *game)
{
		
}
*/


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
	return (true);
}
