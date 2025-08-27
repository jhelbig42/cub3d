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
#include "../includes/structs.h"

#define DOOR_OPEN 3
#define DOOR_CLOSED 2

void	toggle_door(t_game *game)
{
	t_vector_i	pos;

	pos.x = game->player.pos.x;
	pos.y = game->player.pos.y;
	if (game->map.map[pos.y + 1][pos.x] == DOOR_OPEN)
		game->map.map[pos.y + 1][pos.x] = DOOR_CLOSED;
	else if (game->map.map[pos.y + 1][pos.x] == DOOR_CLOSED)
		game->map.map[pos.y + 1][pos.x] = DOOR_OPEN;
	if (game->map.map[pos.y - 1][pos.x] == DOOR_OPEN)
		game->map.map[pos.y - 1][pos.x] = DOOR_CLOSED;
	else if (game->map.map[pos.y - 1][pos.x] == DOOR_CLOSED)
		game->map.map[pos.y - 1][pos.x] = DOOR_OPEN;
	if (game->map.map[pos.y][pos.x + 1] == DOOR_OPEN)
		game->map.map[pos.y][pos.x + 1] = DOOR_CLOSED;
	else if (game->map.map[pos.y][pos.x + 1] == DOOR_CLOSED)
		game->map.map[pos.y][pos.x + 1] = DOOR_OPEN;
	if (game->map.map[pos.y][pos.x - 1] == DOOR_OPEN)
		game->map.map[pos.y][pos.x - 1] = DOOR_CLOSED;
	else if (game->map.map[pos.y][pos.x - 1] == DOOR_CLOSED)
		game->map.map[pos.y][pos.x - 1] = DOOR_OPEN;
}
