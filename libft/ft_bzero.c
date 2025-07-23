/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:38:30 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/14 12:14:39 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	char			*help;

	help = (char *)s;
	i = 0;
	while (i < n)
	{
		help[i] = '\0';
		i++;
	}
}
