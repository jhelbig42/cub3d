/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:36:36 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 15:02:48 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../includes/structs.h"
# include "../utils/utils.h"
# include "../parser/parser.h"

//init.c
bool	game_init(t_game *game, char *map_name);

//tex_init.c
bool	tex_init(t_game *game);

#endif
