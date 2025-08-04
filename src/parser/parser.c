/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:00:25 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/04 09:37:38 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	read_map_data(t_game *game, int fd, char **line)
{
	while (*line)
	{
		if (*line[0] == 'F' || *line[0] == 'C') 
		{
			if (!find_colors(game, *line, *line[0]))
				return (free(line), close(fd), false);
		}
		else if (is_wall_path(*line))
		{
			if (!set_wall_paths(game, *line))
				return (free(*line), close(fd), false);
		}
		else if (*line[0] != '\n')
			break ;
		free(*line);
		*line = get_next_line(fd);
	}
	return (true);
}

bool	read_map(t_game *game, int fd, char **line)
{
	char	**map_str_arr;
	int		i;

	map_str_arr = NULL;
	map_str_arr = init_map_char(map_str_arr);
	if (!map_str_arr)
		return (free(*line), close(fd), false);
	i = 0;
	while (*line)
	{
		map_str_arr[i] = *line;
		*line = get_next_line(fd);
		i++;
	}
	if (!map_str_arr_valid(game, map_str_arr))
		return (free_str_arr(map_str_arr), close (fd), false);
	free_str_arr(map_str_arr);
	return (true);
}

bool	parse_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	fill_default_game(game);
	if (!correct_file_type(map_name))
		return (false);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (print_error("could not open map file"), false);
	line = get_next_line(fd);
	if (!read_map_data(game, fd, &line))
		return (false);
	if (!data_complete(game))
		return (free(line), close(fd), false);
	if (!read_map(game, fd, &line))
		return (false);
	close(fd);
	return (true);
}
