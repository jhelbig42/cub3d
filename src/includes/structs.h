/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:56:39 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 14:17:31 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// structs.h
/*
This file is reserved for all reused struct definitions.
It should not include anything but constants
*/

#ifndef STRUCTS_H
# define STRUCTS_H

# include "./CONSTANTS.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vector_d
{
	double	x;
	double	y;
}	t_vector_d;

typedef struct s_vector_i
{
	int	x;
	int	y;
}	t_vector_i;

typedef struct s_map
{
	int		width;
	int		height;
	int		**map;
}	t_map;

typedef struct s_rgb
{
	short	r;
	short	g;
	short	b;
}	t_rgb;

typedef struct s_player
{
	t_vector_d	pos;
	t_vector_d	dir;
	t_vector_d	plane;
	int			walking;
	int			wall_hit;
	int			rotating;
	int			strafing;
	int			nodding;
	bool		jumping;
	float		jump_offset;
	float		jump_velo;
}	t_player;

typedef struct s_tex
{
	char	*path;
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	char	*addr;
}	t_tex;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	bool		noise;
	bool		shades;
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
	int64_t		last_frame;
	int			len_frame;
	int			horizont;
	t_vector_i	cursor;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_tex		north;
	t_tex		south;
	t_tex		west;
	t_tex		east;
	t_tex		door;
	t_tex		keys0;
	t_tex		keys1;
	int			displays;
	bool		use_mouse;
}	t_game;

#endif
