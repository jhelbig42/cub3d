#ifndef UTILS_H
#define UTILS_H

#include "../includes/CONSTANTS.h"
#include <math.h>

// utils.c
double deg_to_rad(int angle);

// error.c
void print_error(char *msg);

// free.c
void free_split(char **split);

#endif
