/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:00:13 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 12:13:17 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	set_wall_path(void **wall_path, char *line)
{
	char	*path;
    int     fd;
    char    *buf;

    //find path
	path = ft_strtrim(&line[2], " \n");
	if (!path)
		return (print_error("strtrim failed"), false);
    //make sure file exists and it is possible to open
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (print_error("could not open wall file"), free(path), false);
    //possible to read file?
    buf = NULL;
    if (read(fd, buf, 0) < 0)
        return (print_error("could not read from wall file"), free(path), false);
    close(fd);
    //file is closed, safe path
	*wall_path = (void *)path;
	return (true);
}
bool	set_wall_paths(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		{
			if (!set_wall_path(&game->north_path, line))
				return (free(line), false);
		}
		else if (!ft_strncmp(line, "SO", 2))
		{
			if (!set_wall_path(&game->south_path, line))
				return (free(line), false);
		}
		else if (!ft_strncmp(line, "WE", 2))
		{
			if (!set_wall_path(&game->west_path, line))
				return (free(line), false);
		}
		else if (!ft_strncmp(line, "EA", 2))
		{
			if (!set_wall_path(&game->east_path, line))
				return (free(line), false);
		}
	return (true);
}
