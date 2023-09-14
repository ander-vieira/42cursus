/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:12 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/15 00:32:52 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	realloc_result(t_str *result, ssize_t new_l)
{
	char	*old_result;

	if (new_l == result->l)
		return ;
	old_result = result->d;
	result->d = (char *)malloc(sizeof(char) * new_l);
	if (old_result == NULL)
		return ;
	if (result->d != NULL)
		gnl_memcpy(result->d, old_result, result->l);
	free(old_result);
}

static char	add_to_result(t_str *result, t_buf *buf)
{
	ssize_t	newline_pos;
	ssize_t	append_l;

	if (buf->l <= 0)
		return (1);
	newline_pos = find_newline(buf->b, buf->l);
	append_l = buf->l;
	if (newline_pos != -1)
		append_l = newline_pos;
	realloc_result(result, result->l + append_l + 1);
	if (result->d != NULL)
	{
		gnl_memcpy(result->d + result->l, buf->b, append_l);
		result->d[result->l + append_l] = '\0';
		result->l += append_l;
		if (newline_pos != -1)
		{
			buf->l -= newline_pos;
			gnl_memcpy(buf->b, buf->b + newline_pos, buf->l);
			return (0);
		}
		return (1);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char			loop;
	t_str			result;
	static t_buf	buf[FD_LIMIT];

	result.d = NULL;
	result.l = 0;
	loop = 1;
	while (loop > 0)
	{
		loop = add_to_result(&result, &(buf[fd]));
		if (loop > 0)
		{
			buf[fd].l = read(fd, buf[fd].b, sizeof(char) * BUFFER_SIZE);
			if (buf[fd].l <= 0)
				loop = buf[fd].l;
		}
	}
	if (loop == -1 && result.d != NULL)
	{
		free(result.d);
		result.d = NULL;
	}
	return (result.d);
}
