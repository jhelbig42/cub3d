/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:53:31 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 10:05:11 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void walk(t_game *game, int dir)
{
	if (dir > 0)
	{
		game->player.pos_x += game->player.dir_x;
		game->player.pos_y += game->player.dir_y;
	}
	else
	{
		game->player.pos_x -= game->player.dir_x;
		game->player.pos_y -= game->player.dir_y;
	}
}

void rotate(t_game *game, int dir)
{
	t_player *p;
	double	  tmp_x;

	p		   = &game->player;
	tmp_x	   = p->dir_x;
	p->dir_x   = p->dir_x * cos(ROT_ANGLE * dir) - p->dir_y * sin(ROT_ANGLE * dir);
	p->dir_y   = tmp_x * sin(ROT_ANGLE * dir) + p->dir_y * cos(ROT_ANGLE * dir);
	tmp_x	   = p->plane_x;
	p->plane_x = p->plane_x * cos(ROT_ANGLE * dir) - p->plane_y * sin(ROT_ANGLE * dir);
	p->plane_y = tmp_x * sin(ROT_ANGLE * dir) + p->plane_y * cos(ROT_ANGLE * dir);
}
