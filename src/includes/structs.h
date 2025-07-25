/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:56:39 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 12:04:12 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// structs.h
// This file is reserved for all reused struct definitions. It should not include anything but constants

#ifndef STRUCTS_H
# define STRUCTS_H

#include "./CONSTANTS.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		lines; // giving the complete size
	int		col;
	char	**map; // actual map
}	t_map;

typedef struct s_RGB
{
	size_t	R;
	size_t	G;
	size_t	B;
}	t_RGB;

typedef struct s_game
{
	t_map	*map;
	int		player_x; // start but also later current pos
	int		player_y;
	int		player_orient_start; // just for the start N E S W
								// later orientation will be incremental aka complicated
	t_RGB	floor_color;
	t_RGB	ceiling_color;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	void	*wall_graphics[4]; // ein image pro Wandausrichtung?
}	t_game;

#endif
