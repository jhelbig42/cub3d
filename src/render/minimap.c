/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:05:16 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/12 11:23:45 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	x = MM_MARGIN - 1;
	y = MM_MARGIN - 1;
	while (++y < MM_MARGIN + MM_HEIGHT)
	{
		while (++x < MM_MARGIN + MM_WIDTH)
		{
			if (x > MM_MARGIN)
				pixel_put(&game->img, x, SCREEN_HEIGHT - y, 0);
		}
		x = MM_MARGIN - 1;
	}
}
