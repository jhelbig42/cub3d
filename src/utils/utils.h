/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:11:50 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/04 15:11:52 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/CONSTANTS.h"
# include "../includes/structs.h"
# include <math.h>

// utils.c
double	deg_to_rad(int angle);
bool	empty_field(t_map map, t_vector_d pos);

// error.c
void	print_error(char *msg);

// free.c
void	free_split(char **split);

#endif
