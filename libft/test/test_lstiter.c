/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:53:15 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/19 16:57:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	del_c(void *ptr)
{
}

static void	iter(void *ptr)
{
	*((char *)ptr) = 'i';
}

static void	*map(void *ptr)
{
	return (ptr);
}

void	test_lstiter(void)
{
	char	buf[2];
	t_list	*lst;
	t_list	*lst2;

	lst = ft_lstnew(buf);
	ft_lstadd_back(&lst, ft_lstnew(buf + 1));
	lst2 = ft_lstmap(lst, &map, &del_c);
	print_test("ft_lstmap", lst2->content == buf
		&& lst2->next->content == buf + 1);
	ft_lstclear(&lst2, &del_c);
	ft_lstiter(lst, &iter);
	print_test("ft_lstiter", buf[0] == 'i' && buf[1] == 'i');
	ft_lstclear(&lst, &del_c);
}