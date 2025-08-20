/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:53:10 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 10:12:50 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	on_keypress_ascii(int key, t_game *game)
{
	if (key == W)
		game->player.walking = 1;
	if (key == S)
		game->player.walking = -1;
	if (key == A)
		game->player.strafing = -1;
	if (key == D)
		game->player.strafing = 1;
	if (key == I)
		game->player.nodding = 1;
	if (key == K)
		game->player.nodding = -1;
	if (key == N)
		game->noise = !game->noise;
	if (key == M)
		game->shades = !game->shades;
	if (key == X)
		toggle_mouse(game);
	if (key == SPACE)
		if (!game->player.jumping)
			start_jump(game);
	if (key == O)
		open_door(game);
	if (key == C)
		close_door(game);
}

static void	on_keypress_special(int key, t_game *game)
{
	if (key == ESC)
		on_destroy(game);
	if (key == LEFT)
		game->player.rotating = -1;
	if (key == RIGHT)
		game->player.rotating = 1;
	if (key == UP)
		game->player.nodding = 1;
	if (key == DOWN)
		game->player.nodding = -1;
}

int	on_keypress(int key, t_game *game)
{
	if (key <= 122)
		on_keypress_ascii(key, game);
	else
		on_keypress_special(key, game);
	return (0);
}

int	on_keyrelease(int key, t_game *game)
{
	if (key == LEFT || key == RIGHT)
		game->player.rotating = 0;
	if (key == W || key == S)
		game->player.walking = 0;
	if (key == A || key == D)
		game->player.strafing = 0;
	if (key == I || key == K || key == UP || key == DOWN )
		game->player.nodding = 0;
	return (0);
}
