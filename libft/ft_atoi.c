/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:18:59 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/22 12:00:22 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	spaces(char *str, int i);
static int	is_number(char *str, int i);

//arbitrary amount of whitespace allowed
//single sign allowed
int	ft_atoi(const char *nptr)

{
	int	i;
	int	sign;
	int	result;		

	i = 0;
	sign = 1;
	result = 0;
	i = spaces((char *)nptr, i);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && is_number((char *)nptr, i) == 1)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	spaces(char *str, int i)
{
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r'))
	{
		i++;
	}
	return (i);
}

static int	is_number(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = " - 123a235174";

	printf("%d", ft_atoi(str));
	return (0);
}
*/
