/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:55:15 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 14:26:33 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	on_mousemove(int x, int y, t_game *game)
{
	game->cursor.x = x;
	game->cursor.y = y;
	return (0);
}

void	toggle_mouse(t_game *game)
{
	if (game->use_mouse)
		mlx_mouse_show(game->mlx_ptr, game->win_ptr);
	else
		mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
	game->use_mouse = !game->use_mouse;
}
