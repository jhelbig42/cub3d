#ifndef UTILS_H
# define UTILS_H

# include "../includes/CONSTANTS.h"
# include "../includes/structs.h"
# include <math.h>

// utils.c
double deg_to_rad(int angle);

// error.c
void print_error(char *msg);

// free.c
void	free_str_arr(char **str_arr);
void	free_int_arr(int **int_arr, int index);
void	free_paths(t_game *game);

#endif
