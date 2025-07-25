/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:01:16 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 11:03:50 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cube.h"

//find_colors.c
bool	find_colors(t_game *game, char *line, char c);

//find_paths.c
bool	set_wall_path(void **wall_path, char *line);

//parser.c
bool	parse_map(t_game *game, char *map_name);

#endif
