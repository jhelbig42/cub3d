/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CONSTANTS.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:59:11 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 14:03:12 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CONSTANTS.h
// This file only includes definitions and library includes. It does not include any src files!

#ifndef CONSTANTS_H
# define CONSTANTS_H

# include "../../libft/get_next_line.h"
# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//keys
# define ESC 65307

//colors
# define C_NEON_VIOLET 0xFFAB20FD
# define C_NEON_YELLOW 0xFFCFFF04

//stats
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

//map
# define MAX_MAP_LENGTH 200
#endif
