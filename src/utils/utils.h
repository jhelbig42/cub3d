/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:11:50 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/06 15:42:40 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/CONSTANTS.h"
# include "../includes/structs.h"
# include <math.h>

// utils.c
double	deg_to_rad(int angle);
int64_t	get_mills(void);

// error.c
void	print_error(char *msg);

// free.c
void	free_str_arr(char **str_arr);
void	free_int_arr(int **int_arr, int index);
void	free_paths(t_game *game);

#endif
