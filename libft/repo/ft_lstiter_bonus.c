/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:29:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/20 11:28:32 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*fun)(void *))
{
	if (lst != NULL && fun != NULL)
	{
		fun(lst->content);
		ft_lstiter(lst->next, fun);
	}
}
