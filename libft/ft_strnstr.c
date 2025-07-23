/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:50:57 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/14 12:11:18 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//len starts at the beginning of big
#include "libft.h"

static int	find_string(const char *big, const char *little, int i, int len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && len > 0)
	{
		if (big[i] == little[0] && find_string(big, little, i, len) == 1)
			return ((char *)&(big[i]));
		i++;
		len--;
	}
	return ((char *) 0);
}

int	find_string(const char *big, const char *little, int i, int len)
{
	int	j;

	j = 0;
	while (little[j] != '\0')
	{
		if (little[j] != big[i] || len == 0)
			return (0);
		i++;
		j++;
		len--;
	}
	return (1);
}
