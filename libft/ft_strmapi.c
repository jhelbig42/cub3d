/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:42:48 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/19 11:40:22 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	i = 0;
	while (res[i] != '\0')
	{
		res[i] = (*f)(i, res[i]);
		i++;
	}
	return (res);
}
