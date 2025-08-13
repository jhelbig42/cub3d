/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 10:10:32 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_wall_x(t_game *game, int x, int wall_height)
{
	int	y;
	int	top;

	y = game->horizont - wall_height / 2 - 1;
	top = game->horizont + wall_height / 2;
	while (y++ < top)
		pixel_put(&game->img, x, y, C_NEON_BLUE);
}
