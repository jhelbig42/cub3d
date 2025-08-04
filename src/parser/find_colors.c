/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:00:03 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/04 09:41:24 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// F 220,100,0

static void	set_RGB_val(t_rgb *rgb, int i, int val)
{
	if (i == 0)
		rgb->r = val;
	else if (i == 1)
		rgb->g = val;
	else if (i == 2)
		rgb->b = val;
}

static bool	check_RGB_val(char *input, int *val)
{
	*val = ft_atoi(input);
	if (*val == 0 && input[0] != '0')
		return (print_error("RGB values are not given as numbers"), false);
	if (*val < 0 || *val > 255)
		return (print_error("invalid RGB values given"), false);
	return (true);
}

static bool	fill_color(char *line, t_rgb *rgb)
{
	char	**split;
	char	*trim_split;
	int		i;
	int		val;

	split = ft_split(line, ',');
	if (!split)
		return (false);
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (free_str_arr(split),
			print_error("wrong number of RGB values given"), false);
	i = 0;
	while (i < 3)
	{
		trim_split = ft_strtrim(split[i], " \n");
		if (!trim_split)
			return (free_str_arr(split), print_error("ft_strtrim failed"),
				false);
		if (!check_RGB_val(split[i], &val))
			return (free_str_arr(split), free(trim_split), false);
		set_RGB_val(RGB, i++, val);
		free(trim_split);
	}
	free_str_arr(split);
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

