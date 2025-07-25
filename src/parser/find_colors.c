/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:00:03 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 11:13:49 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// F 220,100,0

static bool	fill_color(char *line, t_RGB *RGB)
{
	char	**split;
	char	*trim_split;
	int		i;
	int		val;

	split = ft_split(line, ',');
	if (!split)
		return (false);
	//there must be exactly 3 args given
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (free_split(split), print_error("wrong number of RGB values given"), false);
	i = 0;
	while (i < 3)
	{
		trim_split = ft_strtrim(split[i], " \n");
		if (!trim_split)
			return (free_split(split), print_error("ft_strtrim failed"), false);
		val = ft_atoi(split[i]);
		if (val == 0 && split[i][0] != '0')
			return (free_split(split), free(trim_split), print_error("RGB values are not given as numbers"), false);
		if (val < 0 || val > 255)
			return (free_split(split), free(trim_split), print_error("invalid RGB values given"), false);
		if (i == 0)
			RGB->R = val;
		else if (i == 1)
			RGB->G = val;
		else if (i == 2)
			RGB->B = val;
		i++;
		free(trim_split);
	}
	free_split(split);
	return (true);
}

bool	find_colors(t_game *game, char *line, char c)
{
	if (c == 'F' && !fill_color(&line[1], &game->floor_color))
		return (false);
	if (c == 'C' && !fill_color(&line[1], &game->ceiling_color))
		return (false);
	return (true);
}
