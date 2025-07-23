/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:37:12 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/20 16:05:15 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*spot;
	int		i;

	spot = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			spot = (char *)(s + sizeof(char) * i);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (spot);
}

/*
#include <stdio.h>
int	main (void)
{
	const char *s = "helloex";
	char *res = strrchr(s, 'e');
	printf("%s\n", res);
}
*/
