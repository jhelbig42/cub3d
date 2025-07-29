/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/29 15:50:29 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

void	test_print_game(t_game *game)
{
	printf("ceiling color: R %d G %d B %d\n", game->ceiling_color.R, 
		game->ceiling_color.G, game->ceiling_color.B);
	printf("floor color: R %d G %d B %d\n", game->floor_color.R,
		game->floor_color.G, game->floor_color.B);
	printf("north path: %s\n", (char *)game->north_path);
	printf("south path: %s\n", (char *)game->south_path);
	printf("west path: %s\n", (char *)game->west_path);
	printf("east path: %s\n", (char *)game->east_path);
	printf("Player pos: %f / %f\n", game->player.pos_x, game->player.pos_y);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game = game_init();
	// if (!parse_map(&game, argv[1]))
	// 	printf("map error\n");
	init_test_game(&game);
	if (argv[1])
		printf("Map Name: %s\n", argv[1]);
	//test_print_game(&game);
	mlx_hook(game.win_ptr, EXIT_HOOK, 0, on_destroy, &game);
	mlx_hook(game.win_ptr, KEY_PRESS_HOOK, 1L << 0, on_keypress, &game);
	mlx_loop_hook(game.mlx_ptr, render_frames, &game);
	mlx_loop(game.mlx_ptr);
}
