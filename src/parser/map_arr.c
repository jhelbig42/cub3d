/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:27:07 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/05 09:29:58 by jhelbig          ###   ########.fr       */
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
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.plane.x = -0.66;
		game->player.plane.y = 0;
	}
	else if (pos == 'W')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.plane.x = 0;
		game->player.plane.y = -0.66;
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
			if (!is_valid_sym( map[*i][j]))
				return (print_error("undefined symbols in map"), false);
			if (is_orient( map[*i][j]))
			{
				if (*pos != 'D')
					return (print_error("more that 1 player given in map"),
						false);
				*pos =  map[*i][j];
				game->player.pos.x = *i;
				game->player.pos.y = j;
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

	game->map.map = (int **)malloc(sizeof(int *) * game->map.height);
	if (!game->map.map)
		return (print_error("malloc error map **int arr"), false);
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = (int *)malloc(sizeof(int) * game->map.width);
		if (!game->map.map[i])
			return (print_error("malloc error map int[i] arr"),
				free_int_arr(game->map.map, i), false);
		j = 0;
		while (j < game->map.width)
		{
			if (!map[i][j] || map[i][j] == '\n' || map[i][j] == '0'
				|| map[i][j] == ' ' || is_orient(map[i][j]))
				game->map.map[i][j] = 0;
			else if (map[i][j] == '1')
				game->map.map[i][j] = 1;
			j++;
		}
		i++;
	}
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
		return (print_error("no player given in map"), false);
	set_start_pos(game, pos);
	if (!flood_fill(game, char_map))
		return (false);
	if (!map_into_game(game, char_map))
		return (false);
	return (true);
}
