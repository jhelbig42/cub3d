/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:13:25 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/27 10:47:18 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

bool	empty_field(t_map map, t_vector_d pos)
{
	if (map.map[(int)(pos.y + 0.05)][(int)(pos.x + 0.05)] == 1
		|| map.map[(int)(pos.y - 0.05)][(int)(pos.x + 0.05)] == 1
		|| map.map[(int)(pos.y + 0.05)][(int)(pos.x - 0.05)] == 1
		|| map.map[(int)(pos.y - 0.05)][(int)(pos.x - 0.05)] == 1
		|| map.map[(int)(pos.y + 0.05)][(int)(pos.x + 0.05)] == 2
		|| map.map[(int)(pos.y - 0.05)][(int)(pos.x + 0.05)] == 2
		|| map.map[(int)(pos.y + 0.05)][(int)(pos.x - 0.05)] == 2
		|| map.map[(int)(pos.y - 0.05)][(int)(pos.x - 0.05)] == 2)
		return (false);
	return (true);
}

t_vector_d	rotate_vector(double x, double y, double angle)
{
	t_vector_d	vector;

	vector.x = x * cos(angle) - y * sin(angle);
	vector.y = x * sin(angle) + y * cos(angle);
	return (vector);
}
