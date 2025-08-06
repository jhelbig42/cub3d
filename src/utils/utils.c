/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:18:42 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/06 15:40:13 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	deg_to_rad(int angle)
{
	return ((angle) * M_PI / 180.0);
}

long	get_mills(void)
{
	struct timeval	tv;
	long			mills;

	gettimeofday(&tv, NULL);
	mills = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (mills);
}
