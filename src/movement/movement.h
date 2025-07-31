/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:54:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 09:03:16 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "../includes/CONSTANTS.h"
#include "../includes/structs.h"

void walk(t_game *game, int dir);
void rotate(t_game *game, int dir);
#endif
