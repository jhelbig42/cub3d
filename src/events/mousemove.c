/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:55:15 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/07 16:11:03 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	on_mousemove(int x, int y, t_game *game)
{
	t_vector_d	mouse_vector;
	t_vector_d	new_dir;

	mouse_vector.x = x - game->mouse_pos.x;
	mouse_vector.y = y - game->mouse_pos.y;
	game->mouse_pos.x = x;
	game->mouse_pos.y = y;
	new_dir = rotate_vector(game->player.dir.x, game->player.dir.y,
			deg_to_rad(ROT_ANGLE * mouse_vector.x * -0.2));
	game->player.dir.x = new_dir.x;
	game->player.dir.y = new_dir.y;
	game->horizont += -mouse_vector.y * 3;
	return (0);
}
