/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:29:54 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 21:32:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *)
	, void (*del)(void *))
{
	t_list	*result;
	t_list	*node;

	result = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(fun(lst->content));
		if (node == NULL)
		{
			if (result != NULL)
				ft_lstclear(&result, del);
			return (NULL);
		}
		if (result == NULL)
			result = node;
		else
			ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
