/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:02:11 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/25 11:02:13 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	on_keypress(int key, t_game *game)
{
  //destroy on ESC
  if (key == ESC)
	  on_destroy(game);
  return (0);
}
