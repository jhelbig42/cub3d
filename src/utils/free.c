/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:21:17 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/05 09:51:38 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	free_int_arr(int **int_arr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(int_arr[i]);
		i++;
	}
	free(int_arr);
}

void	free_paths(t_game *game)
{
	free(game->north_path);
	free(game->south_path);
	free(game->west_path);
	free(game->east_path);
}
