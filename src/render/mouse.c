/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:57:56 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 13:54:04 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define MAX_MOUSE_ROT_X 180 //degrees

void	apply_mouse(t_game *game)
{
	t_vector_i	delta;
	float		x_rot;

	delta.x = game->cursor.x - SCREEN_WIDTH / 2;
	delta.y = game->cursor.y - SCREEN_HEIGHT / 2;
	x_rot = map(MAX_MOUSE_ROT_X, 0, SCREEN_WIDTH, fabs((float)delta.x));
	if (delta.x >= 0)
		rotate(game, -x_rot);
	else
		rotate(game, x_rot);
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
