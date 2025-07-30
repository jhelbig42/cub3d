#include "parser.h"

bool    data_complete(t_game *game)
{
    if (game->floor_color.R == -1
        || game->floor_color.G == -1 || game->floor_color.B == -1 
        || game->ceiling_color.R == -1 || game->ceiling_color.G == -1
        || game->ceiling_color.B == -1
        || game->north_path == NULL || game->south_path == NULL
        || game->west_path == NULL  || game->east_path == NULL)
        return (print_error("Incomplete map data given"), false);
    else
        return (true);
}

void    set_start_pos(t_game *game, char pos)
{
    if (pos == 'E')
    {
        game->player.dir_x = 1;
        game->player.dir_y = 0;
        game->player.plane_x = 0;
        game->player.plane_y = -0.66;
    }
    else if (pos == 'S')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
        game->player.plane_x = -0.66;
        game->player.plane_y = 0;
    }
    else if (pos == 'W')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;
        game->player.plane_x = 0;
        game->player.plane_y = -0.66;
    }
}

bool    read_map_char(t_game *game, char **map, int *i, int *width, char *pos)
{
    char    cur;
    int     j;

    while (map[*i])
    {
        j = 0;
        while (map[*i][j])
        {
            cur = map[*i][j];
            if (cur != '0' && cur != '1' && cur != 'N'
                && cur != 'S' && cur != 'E' && cur != 'W' && cur != ' ' && cur != '\n')
                return (print_error("undefined symbols in map"), false);
            if (cur == 'N' || cur == 'S' || cur == 'E' || cur == 'W')
            {
                if (*pos != 'D')
                    return (print_error("more that 1 player given in map"), false);
                *pos = cur;
                game->player.pos_x = *i;
                game->player.pos_y = j;
            }
            if (j > *width)
                *width = j;
            j++;
        }
        *i = *i + 1;
    }
    return (true);
}
//are symbols in map that are not allowed?
//- in der map nur 0, 1 und genau 1 N S E W
//map surrounded by walls
bool map_str_arr_valid(t_game *game, char **map)
{
    int     i;
    char    pos;
    int     width;

    pos = 'D';
    i = 0;
    width = 0;
    
    read_map_char(game, map, &i, &width, &pos);

    game->map.lines = i;
    game->map.col = width;
    if (pos == 'D')
        return (print_error("no player given in map"), false);
    set_start_pos(game, pos);
    //flood fill here
    //return floodfill false
    return (true);
}
