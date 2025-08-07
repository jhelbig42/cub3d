/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:54:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/07 11:21:45 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H
# include "../includes/CONSTANTS.h"
# include "../includes/structs.h"
# include "../utils/utils.h"

void		move_player(t_game *game);

//movement_utils.c
bool		empty_field(t_map map, t_vector_d pos);
t_vector_d	rotate_vector(double x, double y, double angle);

//movement_y.c
void		move_horizont(t_game *game);
void		start_jump(t_game *game);
void		jumping(t_game *game);
#endif
