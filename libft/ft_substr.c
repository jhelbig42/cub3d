/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:40:28 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/22 12:51:54 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substring;
	int					i;
	unsigned int		str_len;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	else if (start >= str_len || len == 0)
		return (ft_strdup(""));
	else if (len >= str_len - start)
		substring = (char *)malloc(sizeof(char) * (str_len - start + 1));
	else
		substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (len > 0 && s[start + i] != '\0')
	{
		substring[i] = s[start + i];
		i++;
		len--;
	}
	substring[i] = '\0';
	return (substring);
}
