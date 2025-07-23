/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:41:32 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/28 13:31:12 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(void *pointer)
{
	int	count;

	if (pointer == NULL)
		return (print_str("(nil)"));
	count = 0;
	count += print_str("0x");
	count += print_ull_base((unsigned long long)pointer,
			"0123456789abcdef", 16);
	return (count);
}
