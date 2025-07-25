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
		return (free_split(split), print_error("no '.' within filename"), false);
	if (ft_strncmp(split[1], "cub", 2) != 0)
		return (free_split(split), print_error("wrong name extension of given filename"), false);
	free_split(split);
	return (true); 
}

//default values in game struct used for checking completeness of map
void	fill_default_game(t_game *game)
{
	game->player_x = -1;
	game->player_y = -1;
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
}

bool	parse_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

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
				return (free(line), false);
		}
		
		if (!set_wall_paths(game, line))
			return (false);
		
        //lies weiter
		//else if (line[0] != '\n')
			//break ;
		free(line);
		line = get_next_line(fd);
	}
    // hier muessen dann alle Daten bis auf die map ausgelesen sein
    // testen ob noch default Werte, wenn ja, dann return false
	free(line);
    /*map muss am Ende stehen
      - in der map nur 0, 1 und genau 1 N S E W
      - laenge und breite bestimmen (eventuell mit gnl? 
            - damit man nur einmal liest.)
      - malloc
      - auslesen

      - surrounded by walls
    */

    //file schliessen
	close(fd);
	return (true);
}
