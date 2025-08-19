/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:27:07 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/12 12:03:44 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_start_pos(t_game *game, char pos)
{
	if (pos == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = -0.66;
	}
	else if (pos == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.plane.x = -0.66;
		game->player.plane.y = 0;
	}
	else if (pos == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = 0.66;
	}
}

bool	is_orient(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	else
		return (false);
}

bool	is_valid_sym(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '1' 
		|| c == '0' || c == ' ' || c == '\n')
		return (true);
	else
		return (false);
}

static bool	check_map_char(t_game *game, char **map, int *i, char *pos)
{
	int		j;

	while (map[*i])
	{
		j = 0;
		while (map[*i][j])
		{
			if (!is_valid_sym(map[*i][j]))
				return (p_err("undefined symbols used"), free_paths(game), false);
			if (is_orient(map[*i][j]))
			{
				if (*pos != 'D')
					return (p_err("more that 1 player given in map"),
						free_paths(game), false);
				*pos = map[*i][j];
				game->player.pos.y = *i;
				game->player.pos.x = j;
			}
			if (j > game->map.width)
				game->map.width = j;
			j++;
		}
		*i = *i + 1;
	}
	return (true);
}

bool	map_into_game(t_game *game, char **map)
{
	int	i;
	int	j;
	int	len;

	game->map.map = (int **)malloc(sizeof(int *) * game->map.height);
	if (!game->map.map)
		return (p_err("malloc error map **int arr"), false);
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[game->map.height - 1 - i] = (int *)malloc(sizeof(int) * game->map.width);
		if (!game->map.map[game->map.height - 1 - i])
			return (p_err("malloc error map int[i] arr"),
				free_int_arr(game->map.map, i, game->map.height), false);
		len = ft_strlen(map[i]);
		j = 0;
		while (j < game->map.width)
		{
			if (j < len && map[i][j] == '1')
				game->map.map[game->map.height - 1 - i][j] = 1;
			else
				game->map.map[game->map.height - 1 - i][j] = 0;
			j++;
		}
		i++;
	}
	game->player.pos.y = game->map.height - 1 - game->player.pos.y;
	return (true);
}

//are symbols in map that are not allowed?
//- in der map nur 0, 1 und genau 1 N S E W
//map surrounded by walls
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
