/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:23:30 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/17 12:09:27 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
			ft_lstlast(*lst)->next = n;
		else
			*lst = n;
	}
}
