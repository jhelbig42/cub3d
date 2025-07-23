/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:10 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/22 12:28:06 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	output_len(int n)
{
	int	len_out;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
		len_out = 1;
	else
		len_out = 0;
	while (n != 0)
	{
		n = n / 10;
		len_out++;
	}
	return (len_out);
}

char	*fill_nbr_str(int len_out, int n, char *out)
{
	while (len_out && n != 0)
	{
		out[len_out - 1] = n % 10 + '0';
		n = n / 10;
		len_out--;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	int		len_out;
	char	*out;

	len_out = output_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	out = (char *)malloc(sizeof(char) * (len_out + 1));
	if (!out)
		return (NULL);
	out[len_out] = '\0';
	if (n == 0)
		out[0] = '0';
	else
	{
		if (n < 0)
		{
			out[0] = '-';
			n = -n;
		}
		out = fill_nbr_str(len_out, n, out);
	}
	return (out);
}
