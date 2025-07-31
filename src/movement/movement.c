/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:53:31 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 09:57:25 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void walk(t_game *game, int dir)
{
	if (!game || !dir)
		return;
}

void rotate(t_game *game, int dir)
{
	t_player *p;
	double	  tmp_x;

	p		   = &game->player;
	tmp_x	   = p->dir_x;
	p->dir_x   = p->dir_x * cos(ROT_ANGLE * dir) - p->dir_y * sin(ROT_ANGLE * dir);
	p->dir_y   = tmp_x * sin(ROT_ANGLE * dir) + p->dir_y * cos(ROT_ANGLE * dir);
	tmp_x	   = p->plane_x;
	p->plane_x = p->plane_x * cos(ROT_ANGLE * dir) - p->plane_y * sin(ROT_ANGLE * dir);
	p->plane_y = tmp_x * sin(ROT_ANGLE * dir) + p->plane_y * cos(ROT_ANGLE * dir);
}
