/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 12:15:48 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	if (!parse_map(argv))
		return (1);
	game = game_init();
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, 
		&on_destroy, &game);
	mlx_loop_hook(game.mlx_ptr, render_frames, &game);
	mlx_loop(game.mlx_ptr);
}
