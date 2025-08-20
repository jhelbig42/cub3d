/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:11:07 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/20 15:11:09 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	decide_sn(t_game *game, t_ray *ray)
{
	if (game->map.map[ray->map.y][ray->map.x] == 2)
		ray->tex = &game->door;
	else if (game->player.pos.y > ray->map.y)
		ray->tex = &game->south;
	else
		ray->tex = &game->north;
}
