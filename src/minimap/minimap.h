/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:57:08 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/14 13:57:08 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
#define MINIMAP_H

#include "../includes/CONSTANTS.h"
#include "../includes/structs.h"
#include "../movement/movement.h"
#include "../raycaster/raycaster.h"

typedef struct s_mmap
{
	t_vector_i p_pos;
	t_vector_i map_dim;
	t_vector_i tl;
	t_vector_i center;
	int		 **map;
} t_mmap;

// minimap.c
void draw_minimap(t_game *game);

// minimap_player.c
void draw_player(t_game *game, t_mmap mm);

#endif
