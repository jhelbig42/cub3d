#include "cube.h"

bool    parse_map(char **argv)
{
    if (!argv)
        return (false);

    /* - leerzeilen und spaces ueberspringen
        - nach keywords suchen NO SO WE EA F C 
        --> fill information into game struct
        - F C Zahlen muessen zwischen 0 und 255 liegen
    */

    /*map muss am Ende stehen
      - in der map nur 0, 1 und genau 1 N S E W
      - laenge und breite bestimmen (eventuell mit gnl? 
            - damit man nur einmal liest.)
      - malloc
      - auslesen

      - surrounded by walls
    */
    return (true);
}