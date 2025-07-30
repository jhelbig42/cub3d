/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:24:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 14:56:53 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int on_destroy(t_game *game)
{
	// destroy images
	mlx_destroy_image(game->mlx_ptr, game->img.img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);

	// frees
	free(game->mlx_ptr);
	free(game->north_path);
	free(game->south_path);
	free(game->west_path);
	free(game->east_path);
	free_int_arr(game->map.map, game->map.lines);
	exit(0);
}
