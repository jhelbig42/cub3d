/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:36:38 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 12:16:45 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	create_img(t_img *img)
{
	reset_img(img, SCREEN_WIDTH, SCREEN_HEIGHT);
	gen_noise(img);
}

int	render_frames(t_game *game)
{
	create_img(&game->img);
	mlx_put_image_to_window(
		game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
	return (0);
}
