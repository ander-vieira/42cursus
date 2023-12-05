/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:33:34 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 20:00:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_gnl_joinline(char *line, char *buf)
{
	char	*result;
	size_t	line_len;
	size_t	buf_len;

	line_len = ft_strlen(line);
	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
		buf_len += 1;
	result = (char *)malloc(sizeof(char) * (line_len + buf_len + 1));
	if (result == NULL)
		return (free(line), NULL);
	ft_memcpy(result, line, line_len);
	ft_memcpy(result + line_len, buf, buf_len);
	result[line_len + buf_len] = '\0';
	free(line);
	return (result);
}

static char	*ft_gnl_readline(t_fd fd, char *buf, t_error *error)
{
	char	*line;
	ssize_t	bytes_read;

	line = ft_gnl_joinline(NULL, buf);
	if (line == NULL)
		return (ft_seterror(error, ERR_MALLOC), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(line, '\n') == -1)
	{
		bytes_read = read(fd, buf, GNL_BUFSIZE);
		if (bytes_read == -1)
			return (buf[0] = '\0', ft_seterror(error, ERR_READ),
				free(line), NULL);
		if (bytes_read == 0 && ft_strlen(line) == 0)
			return (ft_seterror(error, ERR_OK), free(line), NULL);
		buf[bytes_read] = '\0';
		line = ft_gnl_joinline(line, buf);
		if (line == NULL)
			return (ft_seterror(error, ERR_MALLOC), NULL);
	}
	return (ft_seterror(error, ERR_OK), line);
}

static void	ft_gnl_remainder(char *buf)
{
	size_t	buf_len;
	size_t	rest_len;

	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
	{
		buf_len += 1;
		rest_len = ft_strlen(buf + buf_len);
		ft_memcpy(buf, buf + buf_len, rest_len);
		buf[rest_len] = '\0';
	}
	else
		buf[0] = '\0';
}

char	*ft_gnl(t_fd fd, t_error *error)
{
	static char	buf[GNL_FDLIMIT][GNL_BUFSIZE + 1];
	char		*line;

	if (fd < 0)
		return (ft_seterror(error, ERR_GNL_BADFD), NULL);
	line = ft_gnl_readline(fd, buf[fd], error);
	ft_gnl_remainder(buf[fd]);
	return (line);
}
