/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:06:05 by jhelbig           #+#    #+#             */
/*   Updated: 2025/08/05 09:38:44 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

void test_print_game(t_game *game)
{
	printf("ceiling color: R %d G %d B %d\n", game->ceiling_color.r, 
		game->ceiling_color.g, game->ceiling_color.b);
	printf("floor color: R %d G %d B %d\n", game->floor_color.r,
		game->floor_color.g, game->floor_color.b);
	printf("north path: %s\n", (char *)game->north_path);
	printf("south path: %s\n", (char *)game->south_path);
	printf("west path: %s\n", (char *)game->west_path);
	printf("east path: %s\n", (char *)game->east_path);
	printf("height: %d\n", game->map.height);
	printf("width: %d\n", game->map.width);
	printf("player: pos.x: %f, pos.y: %f, dir.x: %f, dir.y: %f, plane.x: %f, plane.y: %f\n",
		game->player.pos.x, game->player.pos.y, game->player.dir.x, game->player.dir.y, game->player.plane.x, game->player.plane.y);
	int i;
	int j;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			printf("%d", game->map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (print_error("no map file given"), 1);
	game = game_init();
	if (!parse_map(&game, argv[1]))
	 	return (1);
	//init_test_game(&game);
	if (argv[1])
		printf("Map Name: %s\n", argv[1]);
	// test_print_game(&game);
	mlx_hook(game.win_ptr, EXIT_HOOK, 0, on_destroy, &game);
	mlx_hook(game.win_ptr, KEY_RELEASE_HOOK, (1L << 1), on_keyrelease, &game);
	mlx_hook(game.win_ptr, KEY_PRESS_HOOK, (1L << 0), on_keypress, &game);
	mlx_loop_hook(game.mlx_ptr, render_frames, &game);
	mlx_loop(game.mlx_ptr);
}
