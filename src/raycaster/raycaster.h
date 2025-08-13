/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:48:18 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/12 10:43:57 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "../includes/CONSTANTS.h"
# include "../includes/structs.h"

void	raycaster(t_game *game);

typedef struct s_ray
{
	double		camera_x;
	t_vector_d	dir;
	t_vector_d	delta;
	t_vector_i	map;
	t_vector_d	side_dist;
	t_vector_i	step;
	bool		hit;
	int			side;
	int			wall_height;
	double		wall_x;
	t_tex		*tex;
}	t_ray;

#endif
