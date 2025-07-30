/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:01:16 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 14:41:45 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/structs.h"
# include "../includes/CONSTANTS.h"
# include "../utils/utils.h"

//complete.c
bool    data_complete(t_game *game);
bool map_str_arr_valid(t_game *game, char **map);

//find_colors.c
bool	find_colors(t_game *game, char *line, char c);

//find_paths.c
bool	is_wall_path(char *line);
bool	set_wall_paths(t_game *game, char *line);

//parser.c
bool	parse_map(t_game *game, char *map_name);

#endif
