#include "cube.h"

// F 220,100,0

static bool    fill_color(char *line, t_RGB *RGB)
{
    char    **split;
    int     i;
    int     val;

    split = ft_split(line, ',');
    if (!split)
        return (false);
    //there must be exactly 3 args given
    if (!split[0] || !split[1] || !split[2] || split[3])
        return (free_split(split), print_error("wrong number of RGB values given"), false);
    i = 0;
    while (i < 3)
    {
        split[i] = ft_strtrim(split[i], " \n");
        if (!split[i])
            return (free_split(split), print_error("ft_strtrim failed"), false);
        printf("val split: %s\n", split[i]);
        val = ft_atoi(split[i]);
        if (val == 0  && split[i][0] != '0')
            return (free_split(split), print_error("RGB values are not given as numbers"), false);
        if (val < 0 || val > 255)
            return (free_split(split), print_error("invalid RGB values given"), false);
        printf("val: %d\n", val);
        if (i == 0)
            RGB->R = val;
        else if (i == 1)
            RGB->G = val;
        else if (i == 2)
            RGB->B = val;
        i++;  
    }
    return (true);
}

bool    find_colors(t_game *game, char *line, char c)
{
    if (c == 'F' && !fill_color(&line[1], &game->floor_color))
            return (false);
    if (c == 'C' && !fill_color(&line[1], &game->ceiling_color))
            return (false);
    return (true);
}
