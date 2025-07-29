#include "parser.h"

bool    data_complete(t_game *game)
{
    if (game->floor_color.R == -1
        || game->floor_color.G == -1 || game->floor_color.B == -1 
        || game->ceiling_color.R == -1 || game->ceiling_color.G == -1
        || game->ceiling_color.B == -1 || game->north_path == NULL
        || game->south_path == NULL || game->west_path == NULL 
        || game->east_path == NULL)
        return (print_error("Incomplete map data given"), false);
    else
        return (true);
}