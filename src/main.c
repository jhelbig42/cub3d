/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 14:43:55 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

void    test_print_game(t_game *game)
{
    printf("ceiling color: R %d G %d B %d\n", game->ceiling_color.R, game->ceiling_color.G, game->ceiling_color.B);
    printf("floor color: R %d G %d B %d\n", game->floor_color.R, game->floor_color.G, game->floor_color.B);
    printf("north path: %s\n", (char *)game->north_path);
    printf("south path: %s\n", (char *)game->south_path);
    printf("west path: %s\n", (char *)game->west_path);
    printf("east path: %s\n", (char *)game->east_path);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	if (!parse_map(&game, argv[1]))
		return (1);
	test_print_game(&game);
	game = game_init();
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, 
		&on_destroy, &game);
	mlx_loop_hook(game.mlx_ptr, render_frames, &game);
	mlx_loop(game.mlx_ptr);
	
}
