/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:20:59 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/20 16:04:21 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//memmove is a memcpy version, that checks for memory overlap first
//slower but safer

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s || d >= s + n)
		return (ft_memcpy(d, src, n));
	else
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n > 0)
		{
			*d = *s;
			d--;
			s--;
			n--;
		}
	}
	return (dest);
}
