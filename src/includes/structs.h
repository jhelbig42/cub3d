/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:56:39 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 16:32:01 by uschmidt         ###   ########.fr       */
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

typedef struct s_RGB
{
	short	R;
	short	G;
	short	B;
}	t_RGB;

typedef struct s_player
{
	t_vector_d	pos;
	t_vector_d	dir;
	t_vector_d	plane;
	int			walking;
	int			rotating;
	int			strafing;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_RGB		floor_color;
	t_RGB		ceiling_color;
	int			width;
	int			height;
	int			horizont;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	void		*north_path;
	void		*south_path;
	void		*west_path;
	void		*east_path;
}	t_game;

#endif
