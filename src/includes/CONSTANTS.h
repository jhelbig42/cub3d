/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CONSTANTS.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:59:11 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/29 12:03:08 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CONSTANTS.h
// This file only includes definitions and library includes. It does not include any src files!

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "../../libft/get_next_line.h"
#include "../../libft/libft.h"
#include "../../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// MLX hooks
#define EXIT_HOOK 17
#define KEY_PRESS_HOOK 2
#define KEY_RELEASE_HOOK 3

// keys
#define ESC 65307
#define LEFT 65361
#define RIGHT 65363
#define UP 65362
#define DOWN 65364

// colors
#define C_NEON_VIOLET 0xFFAB20FD
#define C_NEON_YELLOW 0xFFCFFF04
#define C_NEON_BLUE 0x4D4DFF

// stats
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540
#define ROT_ANGLE 0.01
#define WALK_SPEED 0.03

#endif
