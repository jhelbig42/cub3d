/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:29:13 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/05 09:23:53 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	correct_file_type(char *map_name)
{
	char	**split;

	split = ft_split(map_name, '.');
	if (!split)
		return (print_error("split failed"), false);
	if (!split[1] || split[2])
		return (free_str_arr(split), print_error("no '.' within filename"), false);
	if (ft_strncmp(split[1], "cub", 3) != 0 || (split[1][3] && split[1][3] != '\0'))
		return (free_str_arr(split), 
			print_error("wrong name extension of given filename"), false);
	free_str_arr(split);
	return (true); 
}

//default values in game struct used for checking completeness of map
void	fill_default_game(t_game *game)
{
	game->floor_color.r = -1;
	game->floor_color.g = -1;
	game->floor_color.b = -1;
	game->ceiling_color.r = -1;
	game->ceiling_color.g = -1;
	game->ceiling_color.b = -1;
	game->north_path = NULL;
	game->south_path = NULL;
	game->west_path = NULL;
	game->east_path = NULL;
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
	game->player.dir.x = 0;
	game->player.dir.y = 1;
}

bool	data_complete(t_game *game)
{
	if (game->floor_color.r == -1
		|| game->floor_color.g == -1 || game->floor_color.b == -1 
		|| game->ceiling_color.r == -1 || game->ceiling_color.g == -1
		|| game->ceiling_color.b == -1
		|| game->north_path == NULL || game->south_path == NULL
		|| game->west_path == NULL || game->east_path == NULL)
		return (print_error("Incomplete map data given"), false);
	else
		return (true);
}

char	**init_map_char(char **map)
{
	int	i;

	map = (char **)malloc(sizeof(char *) * MAX_MAP_LENGTH); 
	if (!map)
		return (print_error("error malloc map"), NULL);
	i = 0;
	while (i < MAX_MAP_LENGTH)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}
