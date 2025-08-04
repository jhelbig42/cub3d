/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:26:40 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/04 10:14:06 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	test_print_map(t_game *game, char ***map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.col)
		{
			if ((*map)[i][j])
				printf("%c", (*map)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

//keep the walls, fill the rest with 0
char	**copy_map(t_map *map, char **char_map)
{
	char	**copy;
	int		i;
	int		j;
	int		len;

	copy = (char **)malloc(sizeof(char *) * (map->lines + 1));
	if (!copy)
		return (print_error("malloc failed in floodfill"), NULL);
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		copy[i] = (char *)malloc(sizeof(char) * (map->col + 1));
		if (!copy[i])
			return (print_error("malloc failed in floodfill"),
				free_str_arr(copy), NULL);
		len = ft_strlen(char_map[i]);
		while (j < map->col)
		{
			if (j < len && char_map[i][j] == '1')
				copy[i][j] = char_map[i][j];
			else
				copy[i][j] = '0';
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	fill(t_game *game, char ***map, int i, int j)
{
	if (i < 0 || i >= game->map.lines || j < 0 || j >= game->map.col)
		return ;
	if ((*map)[i][j] != '0')
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
	while (i < game->map.lines)
	{
		if (copy[i][0] == '8' || copy[i][game->map.col - 1] == '8')
			return (print_error("floodfill failed, map not entirely surrounded by walls"), false);
		i++;
	}
	i = 0;
	while (i < game->map.col)
	{
		if (copy[0][i] == '8' || copy[game->map.lines - 1][i] == '8')
			return (print_error("floodfill failed, map not entirely surrounded by walls"), false);
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
	i = game->player.pos_x;
	j = game->player.pos_y;
	fill(game, &copy, i, j);
	if (!test_flood_fill(game, copy))
		return (free_str_arr(copy), false);
	else
		return (free_str_arr(copy), true);
}
