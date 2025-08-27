/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:00:13 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/20 14:36:26 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	set_wall_path(char **wall_path, char *line)
{
	char	*path;
	int		fd;
	char	*buf;

	path = ft_strtrim(&line[2], " \n");
	if (!path)
		return (p_err("strtrim failed"), false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (p_err("could not open wall file"), free(path), false);
	buf = NULL;
	if (read(fd, buf, 0) < 0)
		return (p_err("could not read from wall file"), false);
	close(fd);
	*wall_path = path;
	return (true);
}

bool	set_wall_paths(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (!set_wall_path(&game->north.path, line))
			return (free(line), false);
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		if (!set_wall_path(&game->south.path, line))
			return (free(line), false);
	}
	else if (!ft_strncmp(line, "WE", 2))
	{
		if (!set_wall_path(&game->west.path, line))
			return (free(line), false);
	}
	else if (!ft_strncmp(line, "EA", 2))
	{
		if (!set_wall_path(&game->east.path, line))
			return (free(line), false);
	}
	else if (!ft_strncmp(line, "DO", 2))
	{
		if (!set_wall_path(&game->door.path, line))
			return (free(line), false);
	}
	return (true);
}

bool	is_wall_path(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) 
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "DO", 2))
		return (true);
	else
		return (false);
}
