/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:26:56 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 21:31:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst != NULL && *lst != NULL && del != NULL)
	{
		if ((*lst)->next != NULL)
			ft_lstclear(&((*lst)->next), del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
