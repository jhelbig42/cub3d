/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:00:25 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 13:18:05 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	correct_file_type(char *map_name)
{
	char	**split;

	split = ft_split(map_name, '.');
	if (!split)
		return (print_error("split failed"), false);
	if (!split[1])
		return (free_str_arr(split), print_error("no '.' within filename"), false);
	if (ft_strncmp(split[1], "cub", 2) != 0)
		return (free_str_arr(split), print_error("wrong name extension of given filename"), false);
	free_str_arr(split);
	return (true); 
}

//default values in game struct used for checking completeness of map
void	fill_default_game(t_game *game)
{
	game->floor_color.R = -1;
	game->floor_color.G = -1;
	game->floor_color.B = -1;
	game->ceiling_color.R = -1;
	game->ceiling_color.G = -1;
	game->ceiling_color.B = -1;
	game->north_path = NULL;
	game->south_path = NULL;
	game->west_path = NULL;
	game->east_path = NULL;

	//default orientation is N
    game->player.dir_x = 0;
    game->player.dir_y = 1;
    game->player.plane_x = 0.66;
    game->player.plane_y = 0;
}

bool	parse_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;
	char	**map_str_arr;
	int		i;

	fill_default_game(game);
	//correct name
	if (!correct_file_type(map_name))
		return (false);
    //open file
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (print_error("could not open map file"), false);
    /* - leerzeilen und spaces ueberspringen
        - nach keywords suchen NO SO WE EA F C 
        --> fill information into game struct
        wenn andere Zeichen als type identifier: return false
        - F C Zahlen muessen zwischen 0 und 255 liegen
    */
	line = get_next_line(fd);
	while (line)
	{
        //printf("line read: %s", line);
		if (line[0] == 'F' || line[0] == 'C') 
		{
			if (!find_colors(game, line, line[0]))
				return (free(line), close(fd), false);
		}
		else if (is_wall_path(line))
		{
			if (!set_wall_paths(game, line))
				return (free(line), close(fd), false);
		}
		//newlines ueberspringen, sonst raus
		else if (line[0] != '\n')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	//printf("line: %s", line);
	// hier muessen dann alle Daten bis auf die map ausgelesen sein
    // testen ob noch default Werte, wenn ja, dann return false
	if (!data_complete(game))
		return(free(line), close(fd), false);
	map_str_arr = (char **)malloc(sizeof(char *) * 200); //max 200lines read
	if (!map_str_arr)
		return (print_error("error malloc map"), free(line), close(fd), false);
	i = 0;
    while (line)
	{
		map_str_arr[i] = line;
		line = get_next_line(fd);
		i++;
	}
	if (!map_str_arr_valid(game, map_str_arr))
		return (free_str_arr(map_str_arr), close (fd), false);
	close(fd);
	
	return (true);
}
