/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:13:25 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/04 15:30:43 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

// \a is the system bell - could produce a beep sound
bool	empty_field(t_map map, t_vector_d pos)
{
	if (map.map[(int)pos.y][(int)pos.x])
		return (false);
	return (true);
}

bool	empty_field_with_sound(t_map map, t_vector_d pos)
{
	if (map.map[(int)pos.y][(int)pos.x])
		return (system("paplay /usr/share/sounds/freedesktop/stereo/bell.oga"), false);
	return (true);
}

t_vector_d	rotate_vector(double x, double y, double angle)
{
	t_vector_d	vector;

	vector.x = x * cos(angle) - y * sin(angle);
	vector.y = x * sin(angle) + y * cos(angle);
	return (vector);
}
