/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:53:31 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/06 14:31:34 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

static void	strafe(t_game *game)
{
	int			dir;
	t_vector_d	new_dir;
	t_vector_d	new_pos;

	dir = game->player.strafing;
	new_dir = rotate_vector(
			game->player.dir.x, game->player.dir.y, deg_to_rad(90 * dir));
	new_pos.x = game->player.pos.x + new_dir.x * WALK_SPEED;
	new_pos.y = game->player.pos.y + new_dir.y * WALK_SPEED;
	if (empty_field(game->map, new_pos))
	{
		game->player.pos.x = new_pos.x;
		game->player.pos.y = new_pos.y;
	}
}

static void	walk(t_game *game)
{
	t_vector_d	new_pos;
	t_vector_d	new_dir;

	new_dir.x = game->player.dir.x * WALK_SPEED * game->player.walking;
	new_dir.y = game->player.dir.y * WALK_SPEED * game->player.walking;
	new_pos.x = game->player.pos.x + new_dir.x;
	new_pos.y = game->player.pos.y;
	if (empty_field(game->map, new_pos))
	{
		game->player.pos.x = new_pos.x;
		game->player.pos.y = new_pos.y;
	}
	new_pos.x = game->player.pos.x;
	new_pos.y = game->player.pos.y + new_dir.y;
	if (empty_field(game->map, new_pos))
	{
		game->player.pos.x = new_pos.x;
		game->player.pos.y = new_pos.y;
	}
}

static void	rotate(t_game *game)
{
	t_player	*p;
	int			dir;
	t_vector_d	new_dir;

	p = &game->player;
	dir = p->rotating;
	new_dir = rotate_vector(p->dir.x, p->dir.y,
			deg_to_rad(ROT_ANGLE * dir));
	p->dir.x = new_dir.x;
	p->dir.y = new_dir.y;
	new_dir = rotate_vector(p->plane.x, p->plane.y,
			deg_to_rad(ROT_ANGLE * dir));
	p->plane.x = new_dir.x;
	p->plane.y = new_dir.y;
}

static void	move_horizont(t_game *game)
{
	game->horizont += game->player.nodding * 2;
}

void	move_player(t_game *game)
{
	if (game->player.rotating)
		rotate(game);
	if (game->player.walking)
		walk(game);
	if (game->player.strafing)
		strafe(game);
	if (game->player.nodding)
		move_horizont(game);
}
