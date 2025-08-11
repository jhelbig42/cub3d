/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:57:56 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 14:16:21 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define MAX_MOUSE_ROT_X 180 //degrees
#define MAX_MOUSE_ROT_Y 360 //pixel

void	apply_mouse(t_game *game)
{
	t_vector_i	delta;
	float		rot;

	delta.x = game->cursor.x - SCREEN_WIDTH / 2;
	delta.y = game->cursor.y - SCREEN_HEIGHT / 2;
	rot = map(MAX_MOUSE_ROT_X, 0, SCREEN_WIDTH, fabs((float)delta.x));
	if (delta.x >= 0)
		rotate(game, -rot);
	else
		rotate(game, rot);
	rot = map(MAX_MOUSE_ROT_Y, 0, SCREEN_HEIGHT, fabs((float)delta.y));
	if (delta.y >= 0)
		game->horizont -= rot;
	else
		game->horizont += rot;
	if (game->horizont > SCREEN_HEIGHT)
		game->horizont = SCREEN_HEIGHT;
	if (game->horizont < 0)
		game->horizont = 0;
	mlx_mouse_move(game->mlx_ptr, game->win_ptr,
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
