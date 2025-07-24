/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:08:47 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/24 14:06:06 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cube.h
// This is the main header file. It should include all sources needed by main.
// Don't include this header in other source files to prevent recursion

#ifndef CUBE_H
#define CUBE_H

#include "../init/init.h"
#include "./structs.h"
#include "./CONSTANTS.h"

// destroy.c
int on_destroy(t_game *game);

// keypress.c
int on_keypress(int key, t_game *game);

// parser.c
bool parse_map(char **argv);

#endif
