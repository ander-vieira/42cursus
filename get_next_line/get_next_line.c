/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:12 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/13 21:25:06 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		g_buffer[BUFFER_SIZE];
static ssize_t	g_chunk_len;

static ssize_t	append_buffer(char **result, ssize_t old_len,
	ssize_t append_len)
{
	char	*old_result;

	if (append_len == 0)
		return (old_len);
	old_result = *result;
	*result = (char *)malloc(sizeof(char) * (old_len + append_len + 1));
	if (*result != NULL)
	{
		if (old_result != NULL)
			gnl_memcpy(*result, old_result, old_len);
		gnl_memcpy(*result + old_len, g_buffer, append_len);
		(*result)[old_len + append_len] = '\0';
	}
	if (old_result != NULL)
		free(old_result);
	if (*result == NULL)
		return (-1);
	return (old_len + append_len);
}

static ssize_t	append_to_line(char **result, ssize_t *result_len)
{
	ssize_t	newline_pos;

	newline_pos = find_newline(g_buffer, g_chunk_len);
	if (newline_pos != -1)
	{
		*result_len = append_buffer(result, *result_len, newline_pos);
		if (*result_len == -1)
			return (-1);
		g_chunk_len -= newline_pos;
		gnl_memcpy(g_buffer, g_buffer + newline_pos, g_chunk_len);
		return (1);
	}
	*result_len = append_buffer(result, *result_len, g_chunk_len);
	if (*result_len == -1)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*result;
	ssize_t	result_len;
	ssize_t	done;

	if (g_chunk_len == -1)
		g_chunk_len = 0;
	result = NULL;
	result_len = 0;
	done = append_to_line(&result, &result_len);
	while (done == 0)
	{
		g_chunk_len = read(fd, g_buffer, sizeof(char) * BUFFER_SIZE);
		if (g_chunk_len == -1)
			done = -1;
		else if (g_chunk_len == 0)
			done = 1;
		else
			done = append_to_line(&result, &result_len);
	}
	if (done == -1 && result != NULL)
	{
		free(result);
		result = NULL;
	}
	return (result);
}
