/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:35:38 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/22 14:18:45 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//needs check for integer overflow
//mallocs memory and sets memory to zero

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tlen;

	if (nmemb == 0 || size == 0)
		return (malloc(nmemb * size));
	tlen = nmemb * size;
	if (tlen / size != nmemb)
		return (NULL);
	ptr = malloc(tlen);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, tlen);
	return (ptr);
}
