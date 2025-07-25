#include "parser.h"

bool    set_wall_path(void **wall_path, char *line)
{
    char    *path;
    char    *trim_line;
    //int     fd;
    //char    *buf;

    //find path
    trim_line = ft_strtrim(&line[2], "\n");
    path = ft_strdup(trim_line);
    free(trim_line);
    if (!path)
        return (print_error("strdup or strtrim failed"), false);
    //make sure file exists and it is possible to open
    /*
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (print_error("could not open wall file"), free(path), false);
    //possible to read file?
    buf = NULL;
    if (read(fd, buf, 0) < 0)
        return (print_error("could not read from wall file"), free(path), false);
    close(fd);
    //file is closed, safe path
    */
    *wall_path = (void *)path;
    return (true);
}
