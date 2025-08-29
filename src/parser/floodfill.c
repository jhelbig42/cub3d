/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:26:40 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/12 12:03:44 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*copy_line(t_map *map, char **char_map, int i)
{
	char	*copy;
	int		len;
	int		j;

	copy = (char *)malloc(sizeof(char) * (map->width + 1));
	if (!copy)
		return (p_err("malloc failed in floodfill"), NULL);
	len = ft_strlen(char_map[i]);
	j = 0;
	while (j < map->width)
	{
		if (j < len && char_map[i][j] == '1')
			copy[j] = char_map[i][j];
		else
			copy[j] = '0';
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

//keep the walls, fill the rest with 0
char	**copy_map(t_map *map, char **char_map)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (p_err("malloc failed in floodfill"), NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = copy_line(map, char_map, i);
		if (!copy[i])
			return (free_str_arr(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	fill(t_game *game, char ***map, int i, int j)
{
	if (i < 0 || i >= game->map.height || j < 0 || j >= game->map.width)
		return ;
	if ((*map)[i][j] == ' ')
	{
		(*map)[i][j] = '9';
		return ;
	}
	if ((*map)[i][j] == '1')
		return ;
	(*map)[i][j] = '8';
	fill(game, map, i + 1, j);
	fill(game, map, i - 1, j);
	fill(game, map, i, j + 1);
	fill(game, map, i, j - 1);
}

static bool	test_flood_fill(t_game *game, char **copy)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (copy[i][0] == '8' || copy[i][game->map.width - 1] == '8')
			return (p_err
				("floodfill failed, map not entirely surrounded by walls"),
				false);
		i++;
	}
	i = 0;
	while (i < game->map.width)
	{
		if (copy[0][i] == '8' || copy[game->map.height - 1][i] == '8')
			return (p_err
				("floodfill failed, map not entirely surrounded by walls"),
				false);
		i++;
	}
	return (true);
}

bool	flood_fill(t_game *game, char **char_map)
{
	char	**copy;
	int		i;
	int		j;

	copy = copy_map(&game->map, char_map);
	if (!copy)
		return (false);
	i = game->player.pos.y;
	j = game->player.pos.x;
	fill(game, &copy, i, j);
	if (!test_flood_fill(game, copy))
		return (free_paths(game), free_str_arr(copy), false);
	else
		return (free_str_arr(copy), true);
}
