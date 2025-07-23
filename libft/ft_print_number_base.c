/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:45:08 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/28 13:26:09 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//if would could potentially have invalid bases,
// this would have to be checked before
//here it will be just decimal and hexadecimal - not test necessary
int	print_number_base(long long nbr, char *base, int base_len)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (print_number_base(-nbr, base, base_len) + 1);
	}
	else if (nbr < base_len)
	{
		return (print_char(base[nbr]));
	}
	else
	{
		count = print_number_base(nbr / base_len, base, base_len);
		return (count + print_number_base(nbr % base_len, base, base_len));
	}
}

int	print_ull_base(unsigned long long nbr, char *base, int base_len)
{
	int	count;

	if (nbr < (unsigned long long) base_len)
	{
		return (print_char(base[nbr]));
	}
	else
	{
		count = print_number_base(nbr / base_len, base, base_len);
		return (count + print_number_base(nbr % base_len, base, base_len));
	}
}
