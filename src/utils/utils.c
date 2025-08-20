/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:18:42 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 11:58:50 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	deg_to_rad(int angle)
{
	return (angle * M_PI / 180.0);
}

long	get_mills(void)
{
	struct timeval	tv;
	long			mills;

	gettimeofday(&tv, NULL);
	mills = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (mills);
}

float	map(int range, int t_min, int t_max, float val)
{
	float	perc;
	float	abs;

	abs = t_max - t_min;
	perc = val / abs;
	return (range * perc);
}

int	iabs(int val)
{
	if (val >= 0)
		return (val);
	else
		return (-val);
}
