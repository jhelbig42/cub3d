/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 15:03:27 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

#define EXIT_HOOK 17
#define KEY_PRESS_HOOK 2
#define KEY_RELEASE_HOOK 3

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
	printf("height: %d\n", game->map.lines);
	printf("width: %d\n", game->map.col);
	printf("player: pos_x: %f, pos_y: %f, dir_x: %f, dir_y: %f, plane_x: %f, plane_y: %f\n",
		game->player.pos_x, game->player.pos_y, game->player.dir_x, game->player.dir_y, game->player.plane_x, game->player.plane_y);
	int i;
	int j;
	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.col)
		{
			printf("%d", game->map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game = game_init();
	if (!parse_map(&game, argv[1]))
		return (1);
	test_print_game(&game);
	mlx_hook(game.win_ptr, EXIT_HOOK, 0, on_destroy, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, on_keypress, &game);
	mlx_loop(game.mlx_ptr);
	test_print_game(&game);
	mlx_loop_hook(game.mlx_ptr, render_frames, &game);
	mlx_loop(game.mlx_ptr);
}
