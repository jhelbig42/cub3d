/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:08:47 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 14:41:54 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cube.h
// This is the main header file. It should include all sources needed by main.
// Don't include this header in other source files to prevent recursion

#ifndef CUBE_H
# define CUBE_H

# include "../init/init.h"
# include "./structs.h"
# include "./CONSTANTS.h"
# include "../render/render.h"
# include "../parser/parser.h"

// destroy.c
int		on_destroy(t_game *game);

// keypress.c
int		on_keypress(int key, t_game *game);

// parser.c
bool	parse_map(t_game *game, char *map_name);

#endif
