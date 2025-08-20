/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:24:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 10:14:19 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	on_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_image(game->mlx_ptr, game->north.img);
	mlx_destroy_image(game->mlx_ptr, game->south.img);
	mlx_destroy_image(game->mlx_ptr, game->east.img);
	mlx_destroy_image(game->mlx_ptr, game->west.img);
	if (game->door.path != NULL)
		mlx_destroy_image(game->mlx_ptr, game->door.img);
	mlx_destroy_image(game->mlx_ptr, game->keys0.img);
	mlx_destroy_image(game->mlx_ptr, game->keys1.img);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_paths(game);
	free_int_arr(game->map.map, game->map.height, game->map.height);
	exit(0);
}
