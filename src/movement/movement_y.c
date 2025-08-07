/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:41:45 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/07 09:57:44 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void	jump(t_game *game)
{
	game->player.jump_offset += 1;
}

void	move_horizont(t_game *game)
{
	game->horizont += game->player.nodding * NOD_SPEED;
	if (game->horizont > SCREEN_HEIGHT)
		game->horizont = SCREEN_HEIGHT;
	if (game->horizont < 0)
		game->horizont = 0;
}
