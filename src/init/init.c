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

t_game	game_init(t_game game)
{
	//static t_game	game;

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
