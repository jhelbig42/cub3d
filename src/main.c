/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/24 15:00:31 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int	main(int argc, char **argv)
{
	t_game  *game;

	game = NULL;
    //check args
	if (argc != 2)
		return (1);
	//parse map
	if (!parse_map(argv))
		return (1);
	game = game_init(game);
	if (!game)
		return (1);
	//loading wall images
	//setting start
	//hooks
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, 
		&on_destroy, game);
	//run
	mlx_loop(game->mlx_ptr);
	//clean - is done by on destroy on ESC or closing
}
