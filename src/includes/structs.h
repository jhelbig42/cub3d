/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:56:39 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/24 14:04:31 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// structs.h
// This file is reserved for all reused struct definitions. It should not include anything but constants

#ifndef STRUCTS_H
# define STRUCTS_H

#include "./CONSTANTS.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
	void	*mlx_ptr;
	t_data	mlx_img;
	void	*win_ptr;
	void	*img_ptr[4]; // ein image pro Wandausrichtung?
}	t_game;

#endif
