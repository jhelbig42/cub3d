/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:59:10 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/13 12:19:10 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "../includes/CONSTANTS.h"
# include "../movement/movement.h"
# include "../utils/utils.h"
# include "../includes/structs.h"
# include "../specials/door.h"

// destroy.c
int		on_destroy(t_game *game);

// keypress.c
int		on_keypress(int key, t_game *game);
int		on_keyrelease(int key, t_game *game);

// mousemove.c
int		on_mousemove(int x, int y, t_game *game);
void	toggle_mouse(t_game *game);

#endif
