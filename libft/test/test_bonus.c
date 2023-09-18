/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:48:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:43:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	del_c(void *ptr)
{
	*((char *)ptr) = '0';
}

void	iter(void *ptr)
{
	*((char *)ptr) = 'i';
}

void	*map(void *ptr)
{
	*((char *)ptr) = 'm';
	return (ptr);
}

static void	test_bonus_2(t_list *lst, t_list *lst1, t_list *lst2)
{
	t_list	*lst_m;

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
	lst_m = ft_lstmap(lst, &map, &del_c);
	print_test("ft_lstmap", *(char *)(lst_m->content) == 'm'
		&& *(char *)(lst_m->next->content) == 'm');
	ft_lstclear(&lst_m, &del_c);
}

void	test_bonus(void)
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;
	char	c1;
	char	c2;

	c1 = 'a';
	c2 = 'b';
	lst1 = ft_lstnew(&c1);
	lst2 = ft_lstnew(&c2);
	print_test("ft_lstnew", lst1 != NULL && *(char *)(lst1->content) == 'a'
		&& lst2 != NULL && *(char *)(lst2->content) == 'b');
	test_bonus_2(lst, lst1, lst2);
	printf("%p\n", lst->content);
	ft_lstiter(lst, &iter);
	print_test("ft_lstiter", c1 == 'i' && c2 == 'i');
	ft_lstdelone(lst1, &del_c);
	print_test("ft_lstdelone", c1 == '0');
	ft_lstclear(&lst2, &del_c);
	print_test("ft_lstclear", lst2 == NULL && c2 == '0');
}
