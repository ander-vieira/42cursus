/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:43:52 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/10 17:03:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_readfull_join(char *full, char *buf)
{
	char	*result;

	result = ft_strjoin(2, full, buf);
	free(full);
	return (result);
}

char	*ft_readfull(t_fd fd, t_error *error)
{
	char	buf[READ_BUFSIZE + 1];
	char	*full;
	ssize_t	bytes_read;

	if (fd < 0)
		return (ft_seterror(error, ERR_READ_BADFD), NULL);
	full = ft_strjoin(1, "");
	if (full == NULL)
		return (ft_seterror(error, ERR_MALLOC), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, READ_BUFSIZE);
		if (bytes_read == -1)
			return (ft_seterror(error, ERR_READ), free(full), NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		full = ft_readfull_join(full, buf);
		if (full == NULL)
			return (ft_seterror(error, ERR_MALLOC), NULL);
	}
	return (ft_seterror(error, ERR_OK), full);
}
