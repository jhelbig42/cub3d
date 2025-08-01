#include "parser.h"

static void    set_start_pos(t_game *game, char pos)
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
bool    is_orient(char c)
{
    if (c == 'N' || c =='S' || c == 'W' || c =='E')
        return (true);
    else
        return (false);
}
static bool    check_map_char(t_game *game, char **map, int *i, int *width, char *pos)
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
            if (is_orient(cur))
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

bool    map_into_game(t_game *game, char **map)
{
    int i;
    int j;

    game->map.map = (int **)malloc(sizeof(int *) * game->map.lines);
    if (!game->map.map)
        return (print_error("malloc error map **int arr"), false);
    i = 0;
    while (i < game->map.lines)
    {
        game->map.map[i] = (int *)malloc(sizeof(int) * game->map.col);
        if (!game->map.map[i])
            return (print_error("malloc error map int[i] arr"), free_int_arr(game->map.map, i), false);
        j = 0;
        while (j < game->map.col)
        {
            if (!map[i][j] || map[i][j] =='\n'|| map[i][j] == '0' || map[i][j] == ' ')
                game->map.map[i][j] = 0;
            else if (map[i][j] == '1')
                game->map.map[i][j] = 1;
            //player does not to be marked - is just walkable - w
            else if (is_orient(map[i][j]))
                game->map.map[i][j] = 2;
            j++;
        }
        i++;
    }
    return (true);
}
//are symbols in map that are not allowed?
//- in der map nur 0, 1 und genau 1 N S E W
//map surrounded by walls
bool map_str_arr_valid(t_game *game, char **char_map)
{
    int     i;
    char    pos;
    int     width;

    pos = 'D';
    i = 0;
    width = 0;
    
    check_map_char(game, char_map, &i, &width, &pos);
    game->map.lines = i;
    game->map.col = width;
    if (pos == 'D')
        return (print_error("no player given in map"), false);
    set_start_pos(game, pos);
    if (!flood_fill(game, char_map))
        return(false);
    if (!map_into_game(game, char_map))
        return (false);
    return (true);
}
