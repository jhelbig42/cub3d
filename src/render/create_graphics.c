/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:21:22 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 12:17:48 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*dst;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		offset = y * img->line_length + x * (img->bits_per_pixel / 8);
		dst = img->addr + offset;
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_grad_col(int val, int max,
		unsigned int c_min, unsigned int c_max)
{
	int		d_r;
	int		d_g;
	int		d_b;
	float	factor;

	factor = (float)val / (float)max;
	d_r = (c_max >> 16 & 0xFF) - (c_min >> 16 & 0xFF);
	d_g = (c_max >> 8 & 0xFF) - (c_min >> 8 & 0xFF);
	d_b = (c_max & 0xFF) - (c_min & 0xFF);
	return (
		(0xFF << 24)
		| ((c_min >> 16 & 0xFF) + (int)(factor * d_r)) << 16
		| ((c_min >> 8 & 0xFF) + (int)(factor * d_g)) << 8
		| ((c_min & 0xFF) + (int)(factor * d_b)));
}

void	reset_img(t_img *img, int width, int height)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i++ < width * height)
	{
		pixel_put(img, x, y, 0x0);
		x++;
		if (x > width)
		{
			y++;
			x = 0;
		}
	}
}

void	gen_noise(t_img *img)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (y <= SCREEN_HEIGHT)
	{
		if (++x >= SCREEN_WIDTH && ++y > -2)
			x = 0;
		if (random() * 1 > RAND_MAX / 1.15)
		{
			pixel_put(img, x, y, 
				get_grad_col(
					y, SCREEN_HEIGHT, C_NEON_VIOLET, C_NEON_YELLOW));
		}
	}
}

void	bg_col(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (y <= SCREEN_HEIGHT)
	{
		if (++x >= SCREEN_WIDTH && ++y > -2)
			x = 0;
		if (y < game->horizont)
			pixel_put(&game->img, x, y, game->floor_color);
		else
			pixel_put(&game->img, x, y, game->ceiling_color);
	}
}
