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

t_vector rotate_vector(double x, double y, double angle)
{
	t_vector vector;

	vector.x = x * cos(angle) - y * sin(angle);
	vector.y = x * sin(angle) + y * cos(angle);
	return (vector);
}

static void strafe(t_game *game)
{
	int		 dir;
	t_vector new_dir;
	// TODO: detect wall hit
	dir = game->player.strafing;

	new_dir = rotate_vector(game->player.dir_x, game->player.dir_y, 90 * dir);
	game->player.pos_x += new_dir.x * WALK_SPEED;
	game->player.pos_y += new_dir.y * WALK_SPEED;
}

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
	t_vector  new_dir;

	p		   = &game->player;
	dir		   = p->rotating;
	new_dir	   = rotate_vector(p->dir_x, p->dir_y, ROT_ANGLE * dir);
	p->dir_x   = new_dir.x;
	p->dir_y   = new_dir.y;
	new_dir	   = rotate_vector(p->plane_x, p->plane_y, ROT_ANGLE * dir);
	p->plane_x = new_dir.x;
	p->plane_y = new_dir.y;
}

void move_player(t_game *game)
{
	if (game->player.rotating)
		rotate(game);
	if (game->player.walking)
		walk(game);
	if (game->player.strafing)
		strafe(game);
}
