/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:57:34 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/19 14:53:42 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*(unsigned char *)p1 - *(unsigned char *)p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
