/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:53:31 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 10:57:33 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

static void walk(t_game *game)
{
	int dir;
	// TODO: detect wall hit
	dir = game->player.walking;
	if (dir > 0)
	{
		game->player.pos_x += game->player.dir_x * WALK_SPEED;
		game->player.pos_y += game->player.dir_y * WALK_SPEED;
	}
	else
	{
		game->player.pos_x -= game->player.dir_x * WALK_SPEED;
		game->player.pos_y -= game->player.dir_y * WALK_SPEED;
	}
}

static void rotate(t_game *game)
{
	t_player *p;
	int		  dir;
	double	  tmp_x;

	p		   = &game->player;
	dir		   = p->rotating;
	tmp_x	   = p->dir_x;
	p->dir_x   = p->dir_x * cos(ROT_ANGLE * dir) - p->dir_y * sin(ROT_ANGLE * dir);
	p->dir_y   = tmp_x * sin(ROT_ANGLE * dir) + p->dir_y * cos(ROT_ANGLE * dir);
	tmp_x	   = p->plane_x;
	p->plane_x = p->plane_x * cos(ROT_ANGLE * dir) - p->plane_y * sin(ROT_ANGLE * dir);
	p->plane_y = tmp_x * sin(ROT_ANGLE * dir) + p->plane_y * cos(ROT_ANGLE * dir);
}

void move_player(t_game *game)
{
	if (game->player.rotating)
		rotate(game);
	if (game->player.walking)
		walk(game);
}
