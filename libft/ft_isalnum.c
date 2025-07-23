/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:45:49 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/20 13:30:39 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int	ft_isalpha(unsigned char c);
//int	ft_isdigit(unsigned char c);
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}
