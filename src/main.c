/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/07 10:25:23 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
		return (print_error("no map file given"), 1);
	game = game_init(game);
	if (!parse_map(&game, argv[1]))
		return (1);
	if (argv[1])
		printf("Map Name: %s\n", argv[1]);
	mlx_hook(game.win_ptr, EXIT_HOOK, 0, on_destroy, &game);
	mlx_hook(game.win_ptr, KEY_RELEASE_HOOK, (1L << 1), on_keyrelease, &game);
	mlx_hook(game.win_ptr, KEY_PRESS_HOOK, (1L << 0), on_keypress, &game);
	mlx_loop_hook(game.mlx_ptr, render_frames, &game);
	mlx_loop(game.mlx_ptr);
}
