/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:21:38 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/12 14:26:20 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../includes/CONSTANTS.h"
# include "../includes/structs.h"
# include "../movement/movement.h"
# include "../raycaster/raycaster.h"

typedef struct s_line
{
	int		y;
	int		top;
	double	step_y;
	double	tex_pos;
	int		tex_y;
	int		tex_x;
	int		pos;	
}	t_line;

// render.c
int				render_frames(t_game *game);
int				render_loop_wrapper(void);

// create_graphics.c
void			pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_grad_col(int val, int max,
					unsigned int c_min, unsigned int c_max);
void			reset_img(t_img *img, int width, int height);
void			gen_noise(t_game *game);
void			bg_col(t_game *game);

// draw_wall.c
void			draw_wall_x(t_game *game, t_ray ray, int x);

//mouse.c
void			apply_mouse(t_game *game);

// minimap.c
void			draw_minimap(t_game *game);

#endif
