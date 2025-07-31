/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:53:10 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 10:05:01 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int on_keypress(int key, t_game *game)
{
	// printf("KEY: %d\n", key);
	if (key == ESC)
		on_destroy(game);
	if (key == LEFT)
		rotate(game, -1);
	if (key == RIGHT)
		rotate(game, 1);
	if (key == UP)
		walk(game, 1);
	if (key == DOWN)
		walk(game, -1);
	return (0);
}
