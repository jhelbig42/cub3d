/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:21:38 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 13:17:04 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../includes/CONSTANTS.h"
# include "../includes/structs.h"
# include "../movement/movement.h"
# include "../raycaster/raycaster.h"

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
void			draw_wall_x(t_game *game, int x, int wall_height);

//mouse.c
void			apply_mouse(t_game *game);

#endif
