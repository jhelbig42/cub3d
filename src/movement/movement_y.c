/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:41:45 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/07 11:21:38 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void	start_jump(t_game *game)
{
	game->player.jump_offset = 0.0f;
	game->player.jump_velo = 16.0f;
	game->player.jumping = true;
}

void	jumping(t_game *game)
{
	if (game->player.jumping && game->player.jump_velo >= 0)
	{
		game->player.jump_velo -= JUMP_RISE;
		game->player.jump_offset += game->player.jump_velo;
	}
	else if (game->player.jump_velo <= 0 && game->player.jump_offset >= 0)
	{
		game->player.jump_velo -= JUMP_FALL;
		game->player.jump_offset += game->player.jump_velo;
	}
	else
	{
		game->player.jumping = false;
		game->player.jump_velo = 0.0f;
		game->player.jump_offset = 0.0f;
	}
}

void	move_horizont(t_game *game)
{
	game->horizont += game->player.nodding * NOD_SPEED;
	if (game->horizont > SCREEN_HEIGHT)
		game->horizont = SCREEN_HEIGHT;
	if (game->horizont < 0)
		game->horizont = 0;
}
