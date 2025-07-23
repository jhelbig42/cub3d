/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/23 14:25:26 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
    t_game  game;
    //check args
    if (argc != 2)
        return (1);
    //parse map
    if (!parse_map(argv))
        return (1);
    //build
    game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (exit(1), 1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "cub3d");
	if (!game.win_ptr)
		return (free(game.mlx_ptr), 1);
    //loading wall images
    
    //setting start
    
    //hooks
    mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, 
		&on_destroy, &game);
    //run
	mlx_loop(game.mlx_ptr);
    //clean - is done by on destroy on ESC or closing
}
