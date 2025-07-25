/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:01:41 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 11:01:43 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	on_destroy(t_game *game)
{
    //destroy images
    //mlx_destroy_image(game->mlx_ptr, game->img_ptr[0]); ...

    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	
    //frees
    free(game->mlx_ptr);
    free(game->north_path);
    free(game->south_path);
    free(game->west_path);
    free(game->east_path);
	exit(0);
	return (0);
}
