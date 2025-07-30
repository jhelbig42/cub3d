#ifndef UTILS_H
# define UTILS_H

# include "../includes/CONSTANTS.h"

void    print_error(char *msg);
void	free_str_arr(char **str_arr);
void	free_int_arr(int **int_arr, int index);

#endif