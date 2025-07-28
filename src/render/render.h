/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:21:38 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 12:06:06 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

#include "../includes/CONSTANTS.h"
#include "../includes/structs.h"

// render
int render_frames(t_game *game);
int render_loop_wrapper(void);

// create_graphics
void		 pixel_put(t_img *img, int x, int y, int color);
unsigned int get_grad_col(int val, int max,
						  unsigned int c_min, unsigned int c_max);
void		 reset_img(t_img *img, int width, int height);
void		 gen_noise(t_img *p);

#endif
