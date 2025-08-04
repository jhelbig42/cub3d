/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:13:25 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/04 15:13:42 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

bool	empty_field(t_map map, t_vector_d pos)
{
	if (map.map[(int)pos.x][(int)pos.y])
		return (false);
	return (true);
}
