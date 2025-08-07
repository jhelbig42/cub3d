/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:53:10 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/07 09:47:03 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	on_keypress(int key, t_game *game)
{
	if (key == ESC)
		on_destroy(game);
	if (key == LEFT || key == A)
		game->player.rotating = -1;
	if (key == RIGHT || key == D)
		game->player.rotating = 1;
	if (key == UP || key == W)
		game->player.walking = 1;
	if (key == DOWN || key == S)
		game->player.walking = -1;
	if (key == E)
		game->player.strafing = 1;
	if (key == Q)
		game->player.strafing = -1;
	if (key == I)
		game->player.nodding = 1;
	if (key == K)
		game->player.nodding = -1;
	if (key == N)
		game->noise = !game->noise;
	if (key == M)
		game->shades = !game->shades;
	if (key == SPACE)
		jump(game);
	return (0);
}

int	on_keyrelease(int key, t_game *game)
{
	if (key == LEFT || key == A || key == RIGHT || key == D)
		game->player.rotating = 0;
	if (key == UP || key == W || key == DOWN || key == S)
		game->player.walking = 0;
	if (key == E || key == Q)
		game->player.strafing = 0;
	if (key == I || key == K)
		game->player.nodding = 0;
	return (0);
}
