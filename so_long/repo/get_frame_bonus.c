/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:17:14 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/01 16:02:52 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_uint	get_frame(void)
{
	static t_bool			set;
	static struct timeval	time_start;
	struct timeval			time_cur;
	t_uint					frame;

	if (!set)
	{
		set = TRUE;
		gettimeofday(&time_start, NULL);
		return (0);
	}
	gettimeofday(&time_cur, NULL);
	if (time_cur.tv_usec < time_start.tv_usec)
		time_cur.tv_usec += 1000000;
	frame = (t_uint)(time_cur.tv_usec - time_start.tv_usec) * FPS / 1000000;
	return (frame);
}
