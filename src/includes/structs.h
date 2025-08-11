/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:56:39 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 13:55:11 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// structs.h
// This file is reserved for all reused struct definitions. It should not include anything but constants

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
	int	width;
	int	height;
	int	**map;
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
	int			rotating;
	int			strafing;
	int			nodding;
	bool		jumping;
	float		jump_offset;
	float		jump_velo;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_player	player;
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
	void		*north_path;
	void		*south_path;
	void		*west_path;
	void		*east_path;
	bool		noise;
	bool		shades;
}	t_game;

#endif
