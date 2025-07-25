/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:24:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/25 14:13:53 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int	on_destroy(t_game *game)
{
	//destroy images
	mlx_destroy_image(game->mlx_ptr, game->img.img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	//frees
	free(game->mlx_ptr);
	exit(1);
	return (0);
}
