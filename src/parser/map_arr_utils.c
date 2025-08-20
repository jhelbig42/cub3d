/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:11:03 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/20 14:11:05 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_start_pos(t_game *game, char pos)
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
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

bool	is_valid_sym(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '1' 
		|| c == '0' || c == ' ' || c == '\n');
}

bool	check_map_row(t_game *game, char *row, int i, char *pos)
{
	int		j;
	char	symb;

	j = 0;
	while (row[j])
	{
		symb = row[j];
		if (!is_valid_sym(symb))
			return (p_err("undefined symbols used"), free_paths(game), false);
		if (is_orient(symb))
		{
			if (*pos != 'D')
				return (p_err("more than 1 player given in map"),
					free_paths(game), false);
			*pos = symb;
			game->player.pos.y = i;
			game->player.pos.x = j;
		}
		if (j > game->map.width)
			game->map.width = j;
		j++;
	}
	return (true);
}

bool	check_map_char(t_game *game, char **map, int *i, char *pos)
{
	while (map[*i])
	{
		if (!check_map_row(game, map[*i], *i, pos))
			return (false);
		(*i)++;
	}
	return (true);
}
