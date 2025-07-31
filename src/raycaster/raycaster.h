/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:48:18 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 16:36:23 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "../includes/CONSTANTS.h"
#include "../includes/structs.h"

void raycaster(t_game *game);
void draw_wall_x(t_img img, int x, int wall_height);

typedef struct s_ray
{
	double	   camera_x;
	t_vector_d dir;
	t_vector_d delta;
	t_vector_i map;
	t_vector_d side_dist;
	t_vector_i step;
	bool	   hit;
	int		   side;
} t_ray;

#endif
