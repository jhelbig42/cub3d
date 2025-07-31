/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:53:10 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 10:57:56 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int on_keypress(int key, t_game *game)
{
	// printf("KEY: %d\n", key);
	if (key == ESC)
		on_destroy(game);
	if (key == LEFT)
		game->player.rotating = -1;
	if (key == RIGHT)
		game->player.rotating = 1;
	if (key == UP)
		game->player.walking = 1;
	if (key == DOWN)
		game->player.walking = -1;
	return (0);
}

int on_keyrelease(int key, t_game *game)
{
	if (key == LEFT)
		game->player.rotating = 0;
	if (key == RIGHT)
		game->player.rotating = 0;
	if (key == UP)
		game->player.walking = 0;
	if (key == DOWN)
		game->player.walking = 0;
	return (0);
}
