/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:59:10 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 10:47:36 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "../includes/CONSTANTS.h"
# include "../movement/movement.h"

// destroy.c
int	on_destroy(t_game *game);

// keypress.c
int	on_keypress(int key, t_game *game);
int	on_keyrelease(int key, t_game *game);

#endif
