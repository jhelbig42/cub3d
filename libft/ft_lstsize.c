/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:46 by jhelbig           #+#    #+#             */
/*   Updated: 2024/11/18 11:35:21 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// sicherstellen, dass der pointer zum Beginn der Liste nicht veraendert wird
//--> zweiter Pointer
int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*current;

	len = 0;
	current = lst;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}
