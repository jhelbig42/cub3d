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

void draw_wall_x(t_img img, int x, int wall_height)
{
	int y;
	int top;

	y	= SCREEN_HEIGHT / 2 - wall_height / 2;
	top = SCREEN_HEIGHT / 2 + wall_height / 2;
	while (y++ < top)
		pixel_put(&img, x + 1, y, C_NEON_BLUE);
}
