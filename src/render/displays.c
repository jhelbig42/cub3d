/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:26:45 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/29 11:10:46 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	pixel_put_transparent(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*dst;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		if (color == 0xFFFFFF)
			return ;
		offset = y * img->line_length + x * (img->bits_per_pixel / 8);
		dst = img->addr + offset;
		*(unsigned int *)dst = color;
	}
}

void	put_display(t_img *dst, t_tex *display, int dst_x, int dst_y)
{
	int		x;
	int		y;
	int		color;
	char	*pixel;

	y = 0;
	while (y < display->height)
	{
		x = 0;
		while (x < display->width)
		{
			pixel = display->addr + (y * display->size_line
					+ x * (display->bpp / 8));
			color = *(unsigned int *)pixel;
			pixel_put_transparent(dst, dst_x + x, dst_y + y, color);
			x++;
		}
		y++;
	}
}

void	layer_display(t_game *game)
{
	if (game->displays == 0)
		put_display(&game->img, &game->keys0, 
			SCREEN_WIDTH - KEYS0_WIDTH,
			SCREEN_HEIGHT - KEYS0_HEIGHT);
	else if (game->displays == 1)
		put_display(&game->img, &game->keys1,
			SCREEN_WIDTH / 2 - KEYS1_WIDTH / 2,
			SCREEN_HEIGHT / 2 - KEYS1_HEIGHT / 2);
}
