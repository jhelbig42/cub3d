/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:56:39 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/29 12:16:41 by uschmidt         ###   ########.fr       */
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
	int		width;
	int		height;
	int		**map;
}	t_map;

typedef struct s_RGB
{
	short	R;
	short	G;
	short	B;
}	t_RGB;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_RGB		floor_color;
	t_RGB		ceiling_color;
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	void		*north_path;
	void		*south_path;
	void		*west_path;
	void		*east_path;
}	t_game;

#endif
