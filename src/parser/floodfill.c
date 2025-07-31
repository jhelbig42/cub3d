#include "parser.h"

void	test_print_map(t_game *game, int ***map)
{
	int i;
	int j;
	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.col)
		{
			printf("%d", *map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		**copy_map(t_map *map)
{
	int **copy;
	int i;
	int	j;
	copy = (int **)malloc(sizeof(int *) * map->lines);
	if (!copy)
		return (print_error("malloc failed in floodfill"), NULL);
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		copy[i] = (int *)malloc(sizeof(int) * map->col);
		if (!copy[i])
			return (print_error("malloc failed in floodfill"), free_int_arr(copy, i), NULL);
		while (j < map->col)
		{
			copy[i][j] = map->map[i][j];
			j++;
		}
	}
	return (copy);
}

void	fill(int ***map, int i, int j)
{
	if (*map[i][j] == 0)
		*map[i][j] = 8;
	if (*map[i + 1][j])
		fill(map, i + 1, j);
	if (*map[i - 1][j])
		fill(map, i - 1, j);
	if (*map[i][j + 1])
		fill(map, i, j + 1);
	if (*map[i][j - 1])
		fill(map, i, j - 1);
}

bool	flood_fill(t_game *game)
{
	int	**copy;
	//int	i;
	//int j;

	copy = copy_map(&game->map);
	//i = game->player.pos_x;
	//j = game->player.pos_y;

	//fill(&copy, i, j);
	test_print_map(game, &copy);
	//test success of fill
	free_int_arr(copy, game->map.lines);

	return(true);
}