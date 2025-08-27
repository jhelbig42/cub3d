/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:13:25 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/27 10:36:49 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

bool	empty_field(t_game	*game, t_vector_d pos)
{
	if (game->map.map[(int)pos.y][(int)pos.x] == 1
		|| game->map.map[(int)pos.y][(int)pos.x] == 2)
	{
		game->player.wall_hit = 10;
		return (false);
	}
	return (true);
}

t_vector_d	rotate_vector(double x, double y, double angle)
{
	t_vector_d	vector;

	vector.x = x * cos(angle) - y * sin(angle);
	vector.y = x * sin(angle) + y * cos(angle);
	return (vector);
}
