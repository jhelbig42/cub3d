#include "cube.h"
/*
static bool is_space(char c)
{
    if (c == ' ')
        return (true);
    return (false);
}
*/

bool    correct_file_type(char *map_name)
{
    char    **split;

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

bool    parse_map(t_game *game, char *map_name)
{
    int     fd;
    char    *line;

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
        wenn andere Zeichen also type indentifier: return false
        - F C Zahlen muessen zwischen 0 und 255 liegen
    */
    line = get_next_line(fd);
    
    while (line)
    {
        printf("line read: %s", line);
        if (line[0] == 'F' || line[0] == 'C') 
        {
            if (!find_colors(game, line, line[0]))
                return (false);
        }
        //lies weiter
        else if (!(line[0] == '\n' || line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E'))
            break ;
        free(line);
        line = get_next_line(fd);
    }
    // hier muessen dann alle Daten bis auf die map ausgelesen sein
    // testen ob noch default Werte, wenn ja, dann return false
   

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
