/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:50:06 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/19 12:14:40 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (n == i)
		return (0);
	if (((unsigned char)s1[i]) - ((unsigned char)s2[i]) < 0)
		return (-1);
	if (((unsigned char)(s1[i])) - ((unsigned char)s2[i]) > 0)
		return (1);
	return (0);
}
