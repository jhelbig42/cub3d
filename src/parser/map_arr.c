/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:27:07 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/27 10:53:55 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_line(t_game *game, int i, char **map)
{
	int	len;
	int	j;

	len = ft_strlen(map[i]);
	j = 0;
	while (j < game->map.width)
	{
		if (j < len && map[i][j] == '1')
			game->map.map[game->map.height - 1 - i][j] = 1;
		else if (j < len && map[i][j] == 'D')
			game->map.map[game->map.height - 1 - i][j] = 2;
		else
			game->map.map[game->map.height - 1 - i][j] = 0;
		j++;
	}
}

static bool	alloc_map_rows(t_game *game)
{
	int	i;

	game->map.map = (int **)malloc(sizeof(int *) * game->map.height);
	if (!game->map.map)
		return (p_err("malloc error map **int arr"), false);
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[game->map.height - 1 - i]
			= (int *)malloc(sizeof(int) * game->map.width);
		if (!game->map.map[game->map.height - 1 - i])
		{
			free_int_arr(game->map.map, i, game->map.height);
			return (p_err("malloc error map int[i] arr"), false);
		}
		i++;
	}
	return (true);
}

static bool	fill_map_array(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		set_line(game, i, map);
		i++;
	}
	game->player.pos.y = game->map.height - 1 - game->player.pos.y;
	return (true);
}

bool	map_into_game(t_game *game, char **map)
{
	if (!alloc_map_rows(game))
		return (false);
	if (!fill_map_array(game, map))
		return (false);
	return (true);
}

bool	map_str_arr_valid(t_game *game, char **char_map)
{
	int		i;
	char	pos;

	pos = 'D';
	i = 0;
	if (!check_map_char(game, char_map, &i, &pos))
		return (false);
	game->map.height = i;
	if (pos == 'D')
		return (free_paths(game), p_err("no player given in map"), false);
	set_start_pos(game, pos);
	if (!flood_fill(game, char_map))
		return (false);
	if (!map_into_game(game, char_map))
		return (false);
	return (true);
}
