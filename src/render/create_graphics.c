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

	if (max < 0)
		max = SCREEN_HEIGHT;
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

void	gen_noise(t_game *game)
{
	int	x;
	int	y;
	int	col;

	x = -1;
	y = -1;
	while (y <= SCREEN_HEIGHT)
	{
		if (++x >= SCREEN_WIDTH && ++y > -2)
			x = 0;
		if (y <= game->horizont)
			col = get_grad_col(
					y, game->horizont, C_NEON_VIOLET, 0x0); 
		else
			col = get_grad_col(
					game->horizont, y, C_NEON_YELLOW, 0x0); 
		if (random() * 1 > RAND_MAX / 1.15)
			pixel_put(&game->img, x, y, col);
	}
}

void	bg_col(t_game *game)
{
	int	x;
	int	y;
	int	col;

	y = -1;
	while (++y <= SCREEN_HEIGHT)
	{
		if (game->shades && y < game->horizont)
			col = get_grad_col(
					y, game->horizont, 0x0, game->floor_color); 
		else if (game->shades)
			col = get_grad_col(
					y, SCREEN_HEIGHT, game->ceiling_color, 0x0); 
		else if (y < game->horizont)
			col = game->floor_color;
		else
			col = game->ceiling_color;
		x = -1;
		while (++x <= SCREEN_WIDTH)
			pixel_put(&game->img, x, y, col);
	}
}
