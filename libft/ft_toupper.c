/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:01:06 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/22 14:01:25 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c == EOF)
		return (EOF);
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return ((unsigned char)c - 32);
	else
		return ((unsigned char)c);
}
