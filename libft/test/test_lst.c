/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:48:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/19 17:00:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	del_c(void *ptr)
{
	*((char *)ptr) = '0';
}

void	test_lst(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;
	char	buf[2];

	lst1 = ft_lstnew(buf);
	lst2 = ft_lstnew(buf + 1);
	print_test("ft_lstnew", lst1 != NULL && lst1->content == buf
		&& lst2 != NULL && lst2->content == buf + 1);
	print_test("ft_lstsize 1", ft_lstsize(lst1) == 1 && ft_lstsize(lst2) == 1);
	print_test("ft_lstsize 2", ft_lstsize(NULL) == 0);
	lst = lst1;
	ft_lstadd_front(&lst, lst2);
	print_test("ft_lstadd_front", lst == lst2 && lst->next == lst1);
	lst->next = NULL;
	lst = lst1;
	ft_lstadd_back(&lst, lst2);
	print_test("ft_lstadd_back", lst == lst1 && lst->next == lst2);
	print_test("ft_lstsize 3", ft_lstsize(lst) == 2);
	print_test("ft_lstlast", ft_lstlast(lst) == lst2);
	ft_lstdelone(lst1, &del_c);
	print_test("ft_lstdelone", buf[0] == '0');
	ft_lstclear(&lst2, &del_c);
	print_test("ft_lstclear", lst2 == NULL && buf[1] == '0');
}
