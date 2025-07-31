/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:36:38 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 10:34:05 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void create_img(t_game *game)
{
	reset_img(&game->img, SCREEN_WIDTH, SCREEN_HEIGHT);
	gen_noise(&game->img);
	raycaster(game);
}

int render_frames(t_game *game)
{
	move_player(game);
	create_img(game);
	mlx_put_image_to_window(
		game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
	return (0);
}
