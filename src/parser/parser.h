/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:01:16 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/20 14:10:08 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/structs.h"
# include "../includes/CONSTANTS.h"
# include "../utils/utils.h"

//map_arr.c
bool	map_str_arr_valid(t_game *game, char **map);

//map_arr_utils.c
bool	check_map_char(t_game *game, char **map, int *i, char *pos);
void	set_start_pos(t_game *game, char pos);

//find_colors.c
bool	find_colors(t_game *game, char *line, char c);

//find_paths.c
bool	is_wall_path(char *line);
bool	set_wall_paths(t_game *game, char *line);

//parser.c
bool	parse_map(t_game *game, char *map_name);

//utils.c
bool	correct_file_type(char *map_name);
bool	data_complete(t_game *game);
char	**init_map_char(char **map);

//floodfill.c
bool	flood_fill(t_game *game, char **char_map);

#endif
