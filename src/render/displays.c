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

void    put_display(t_img *dst, t_tex *display, int dst_x, int dst_y)
{
    int		x;
	int 	y;
    int		color;
    char	*pixel;

	y = 0;

    while (y < display->height)
    {
		x = 0;
		while (x < display->width)
        {
            pixel = display->addr + (y * display->size_line + x * (display->bpp / 8));
            color = *(unsigned int *)pixel;

            // draw only if not white
            pixel_put_transparent(dst, dst_x + x, dst_y + y, color);
			x++;
		}
		y++;
    }
}

void	layer_display(t_game *game)
{
	//printf("%d\n", game->displays);
	if (game->displays == 0)
		put_display(&game->img, &game->keys0, 750, 500);
	else if (game->displays == 1)
		put_display(&game->img, &game->keys1, 300, 450);
	
}