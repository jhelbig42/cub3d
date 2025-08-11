/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:36:38 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 14:25:01 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

bool	next_frame(t_game *game)
{
	int64_t	mills;

	mills = get_mills();
	if (mills - game->last_frame > game->len_frame)
	{
		game->last_frame = mills;
		return (true);
	}
	return (false);
}

bool	next_move(t_game *game)
{
	int64_t	mills;

	mills = get_mills();
	if (mills - game->last_frame > game->len_frame)
	{
		game->last_frame = mills;
		return (true);
	}
	return (false);
}

void	create_img(t_game *game)
{
	reset_img(&game->img, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->noise)
		gen_noise(game);
	else
		bg_col(game);
	raycaster(game);
}

// update gamestate always
int	render_frames(t_game *game)
{
	if (next_frame(game))
	{
		create_img(game);
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
		move_player(game);
		if (game->use_mouse)
			apply_mouse(game);
	}
	return (0);
}
