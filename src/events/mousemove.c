/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:55:15 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 13:00:48 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	on_mousemove(int x, int y, t_game *game)
{
	game->cursor.x = x;
	game->cursor.y = y;
	return (0);
}
