#ifndef PARSER_H
# define PARSER_H

# include "../cube.h"

//find_colors.c
bool    find_colors(t_game *game, char *line, char c);

//find_paths.c
bool    set_wall_path(void **wall_path, char *line);

//parser.c
bool    parse_map(t_game *game, char *map_name);


#endif