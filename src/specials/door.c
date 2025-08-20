/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:23:35 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/20 10:24:43 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

void	open_door(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->map.map[y + 1][x] == 2)
		game->map.map[y + 1][x] = 3;
	else if (game->map.map[y - 1][x] == 2)
		game->map.map[y - 1][x] = 3;
	else if (game->map.map[y][x + 1] == 2)
		game->map.map[y][x + 1] = 3;
	else if (game->map.map[y][x - 1] == 2)
		game->map.map[y][x - 1] = 3;
}

void	close_door(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->map.map[y + 1][x] == 3)
		game->map.map[y + 1][x] = 2;
	else if (game->map.map[y - 1][x] == 3)
		game->map.map[y - 1][x] = 2;
	else if (game->map.map[y][x + 1] == 3)
		game->map.map[y][x + 1] = 2;
	else if (game->map.map[y][x - 1] == 3)
		game->map.map[y][x - 1] = 2;
}
