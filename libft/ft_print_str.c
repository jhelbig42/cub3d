/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:48:13 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/28 13:35:54 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	int	count;

	if (str == NULL)
	{
		return (print_str("(null)"));
	}
	count = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		count++;
		str++;
	}
	return (count);
}
