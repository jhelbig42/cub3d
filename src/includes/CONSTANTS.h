/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CONSTANTS.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:59:11 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/27 10:43:28 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CONSTANTS.h
// This file only includes definitions and library includes.
// It does not include any src files!

#ifndef CONSTANTS_H
# define CONSTANTS_H

# include "../../libft/get_next_line_custom.h"
# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

//displays
# define KEYS0 "./displays/keys0.xpm"
# define KEYS1 "./displays/keys1.xpm"

// MLX hooks
# define EXIT_HOOK 17
# define KEY_PRESS_HOOK 2
# define KEY_RELEASE_HOOK 3
# define KEY_MOUSE_MOVE_HOOK 6

// keys
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define SPACE 32
# define A 97
# define S 115
# define D 100
# define W 119
# define Q 113
# define M 109
# define N 110
# define E 101
# define I 105
# define K 107
# define L 108
# define X 120
# define O 111
# define C 99

// colors
# define C_NEON_VIOLET 0xFFAB20FD
# define C_NEON_YELLOW 0xFFCFFF04
# define C_NEON_BLUE 0x4D4DFF
# define C_MM_SHAD 0x555555
// stats
# define SCREEN_WIDTH 960
# define SCREEN_HEIGHT 540
# define ROT_ANGLE 2.5
# define WALK_SPEED 0.06
# define NOD_SPEED 16
# define FRAME_RATE 60
# define JUMP_SPEED_START 24.0f
# define JUMP_RISE 1
# define JUMP_FALL 2.5
# define MAX_MOUSE_ROT_X 180 // degrees
# define MAX_MOUSE_ROT_Y 360 // pixel

// map
# define MAX_MAP_LENGTH 200

// minimap
# define MM_WIDTH 200
# define MM_HEIGHT 150
# define MM_MARGIN 10
# define MM_ZOOM 10
# define MM_VIEW_CONE 40

#endif
