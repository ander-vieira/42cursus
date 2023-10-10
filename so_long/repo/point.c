/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:37:03 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/10 13:37:03 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	*sl_point_new(size_t x, size_t y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	point->next = NULL;
	return (point);
}

void	*sl_point_free(t_point *point)
{
	if (point != NULL)
	{
		sl_point_free(point->next);
		free(point);
	}
	return (NULL);
}

void	sl_point_add(t_point **list, t_point *point)
{
	if (list == NULL || point == NULL)
		return ;
	point->next = *list;
	*list = point;
}

char	sl_point_remove(t_point **list, t_point *point)
{
	if (list == NULL || *list == NULL || point == NULL)
		return (0);
	if ((*list)->x == point->x && (*list)->y == point->y)
	{
		*list = (*list)->next;
		return (1);
	}
	else
		return (sl_point_remove(&((*list)->next), point));
}
