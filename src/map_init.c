#include "cube.h"

// F 220,100,0

bool    fill_color(t_game *game, char *line, char c)
{
    char    **split;
    int     i;
    int     val;
    t_RGB   RGB;

    split = ft_split(line, ',');
    if (!split)
        return (false);
    //there must be exactly 3 args given
    if (!split[0] || !split[1] || !split[2] || split[3])
        return (free_split(split), print_error("wrong number of RGB values given"), false);
    if (c == 'F')
        RGB = game->
    i = 0;
    while (i < 3)
    {
        split[i] = ft_strtrim(split[i], " ");
        if (!split[i])
            return (free_split(split), print_error("ft_strtrim failed"), false);
        val = ft_atoi(split[i]);
        if (val == 0  && split[i][0] != '0')
            return (free_split(split), print_error("RGB values are not given as numbers"), false);
        if (val < 0 || val > 255)
            return (free_split(split), print_error("invalid RGB values given"), false);    
    }

}