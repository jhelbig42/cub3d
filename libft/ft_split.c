/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:21:46 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/22 14:09:23 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

//getting word_len starting at first non-c char,
//going until next c or end of string
static int	find_word_len(const char *s, char c)
{
	int		word_len;

	word_len = 0;
	while (*s != c && *s != '\0')
	{
		word_len++;
		s++;
	}
	return (word_len);
}

char	**free_previous(char **split, int i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;
	int		word_len;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		word_len = find_word_len(s, c);
		split[i] = ft_substr(s, 0, word_len);
		if (!split[i])
			return (free_previous(split, i));
		i++;
		s = s + word_len;
	}
	split[i] = NULL;
	return (split);
}
