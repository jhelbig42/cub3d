/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:21:19 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/22 12:42:34 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && is_in_set(set, s1[start]) == 1)
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (is_in_set(set, s1[end]) == 1)
		end--;
	trim = ft_substr(s1, start, end - start + 1);
	if (!trim)
		return (NULL);
	return (trim);
}
