/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:29:13 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/12 12:03:44 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	correct_file_type(char *map_name)
{
	char	**split;

	split = ft_split(map_name, '.');
	if (!split)
		return (p_err("split failed"), false);
	if (!split[1] || split[2])
		return (free_str_arr(split), p_err("no '.' within filename"),
			false);
	if (ft_strncmp(split[1], "cub", 3) != 0
		|| (split[1][3] && split[1][3] != '\0'))
		return (free_str_arr(split), 
			p_err("wrong name extension of given filename"), false);
	free_str_arr(split);
	return (true); 
}

//default values in game struct used for checking completeness of map
void	fill_default_game(t_game *game)
{
	game->floor_color = -1;
	game->ceiling_color = -1;
	game->north.path = NULL;
	game->south.path = NULL;
	game->west.path = NULL;
	game->east.path = NULL;
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
	game->player.dir.x = 0;
	game->player.dir.y = 1;
	game->map.width = 0;
	game->map.height = 0;
}

bool	data_complete(t_game *game)
{
	if (game->floor_color == -1 || game->ceiling_color == -1
		|| game->north.path == NULL || game->south.path == NULL
		|| game->west.path == NULL || game->east.path == NULL)
		return (p_err("Incomplete map data given"),
			free_paths(game), false);
	else
		return (true);
}

char	**init_map_char(char **map)
{
	int	i;

	map = (char **)malloc(sizeof(char *) * MAX_MAP_LENGTH); 
	if (!map)
		return (p_err("error malloc map"), NULL);
	i = 0;
	while (i < MAX_MAP_LENGTH)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}
