/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:12 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/13 10:08:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_memcpy(char *dest, char *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

static ssize_t	read_chunk(int fd, char *buffer)
{
	ssize_t	chunk_len;
	ssize_t	read_len;

	chunk_len = 0;
	read_len = 1;
	while (chunk_len < BUFFER_SIZE && read_len == 1)
	{
		read_len = read(fd, buffer + chunk_len, sizeof(char));
		chunk_len++;
		if (buffer[chunk_len] == '\n')
			break ;
	}
	if (read_len == -1)
		return (-1);
	return (chunk_len);
}

static ssize_t	append_result(char **result, char *buffer, ssize_t old_len
	, ssize_t chunk_len)
{
	char	*old_result;

	if (chunk_len == 0)
		return (old_len);
	old_result = *result;
	*result = (char *)malloc(sizeof(char) * (old_len + chunk_len + 1));
	if (*result != NULL)
	{
		if (old_result != NULL)
			gnl_memcpy(*result, old_result, old_len);
		gnl_memcpy(*result + old_len, buffer, chunk_len);
		(*result)[old_len + chunk_len] = '\0';
	}
	if (old_result != NULL)
		free(old_result);
	if (*result == NULL)
		return (-1);
	return (old_len + chunk_len);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*result;
	ssize_t	result_len;
	ssize_t	chunk_len;

	result = NULL;
	result_len = 0;
	chunk_len = BUFFER_SIZE;
	while (chunk_len == BUFFER_SIZE)
	{
		chunk_len = read_chunk(fd, buffer);
		if (chunk_len == -1)
		{
			if (result != NULL)
				free(result);
			return (NULL);
		}
		result_len = append_result(result, buffer, result_len, chunk_len);
		if (result_len == -1)
			return (NULL);
	}
	return (result);
}
