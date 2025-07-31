/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:53:31 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 15:11:11 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

t_vector_d rotate_vector(double x, double y, double angle)
{
	t_vector_d vector;

	vector.x = x * cos(angle) - y * sin(angle);
	vector.y = x * sin(angle) + y * cos(angle);
	return (vector);
}

static void strafe(t_game *game)
{
	int		   dir;
	t_vector_d new_dir;
	// TODO: detect wall hit
	dir = game->player.strafing;

	new_dir = rotate_vector(
		game->player.dir.x, game->player.dir.y, deg_to_rad(90 * dir));
	game->player.pos.x += new_dir.x * WALK_SPEED;
	game->player.pos.y += new_dir.y * WALK_SPEED;
}

static void walk(t_game *game)
{
	int dir;
	// TODO: detect wall hit
	dir = game->player.walking;
	if (dir > 0)
	{
		game->player.pos.x += game->player.dir.x * WALK_SPEED;
		game->player.pos.y += game->player.dir.y * WALK_SPEED;
	}
	else
	{
		game->player.pos.x -= game->player.dir.x * WALK_SPEED;
		game->player.pos.y -= game->player.dir.y * WALK_SPEED;
	}
}

static void rotate(t_game *game)
{
	t_player  *p;
	int		   dir;
	t_vector_d new_dir;

	p		   = &game->player;
	dir		   = p->rotating;
	new_dir	   = rotate_vector(p->dir.x, p->dir.y, deg_to_rad(ROT_ANGLE * dir));
	p->dir.x   = new_dir.x;
	p->dir.y   = new_dir.y;
	new_dir	   = rotate_vector(p->plane.x, p->plane.y, deg_to_rad(ROT_ANGLE * dir));
	p->plane.x = new_dir.x;
	p->plane.y = new_dir.y;
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
