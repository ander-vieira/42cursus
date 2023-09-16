/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:29:54 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 21:57:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *)
	, void (*del)(void *))
{
	t_list	*result;
	void	*content;

	if (lst != NULL)
	{
		content = fun(lst->content);
		result = ft_lstnew(content);
		if (result == NULL)
		{
			del(content);
			return (NULL);
		}
		if (lst->next != NULL)
		{
			result->next = ft_lstmap(lst->next, fun, del);
			if (result->next == NULL)
			{
				ft_lstdelone(result, del);
				return (NULL);
			}
		}
		return (result);
	}
	return (NULL);
}
