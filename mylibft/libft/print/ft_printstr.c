/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:48 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

/*
 *	Print a string to a file descriptor
 *	Prints "(null)" if the string is a null pointer
 *
 *	Arguments:
 *	- fd: the file descriptor
 *	- str: the string
 *
 *	Return value:
 *	- The number of bytes written, or -1 if write error
 */
int	ft_printstr(t_fd fd, char *str)
{
	if (str == NULL)
		return (ft_printstr(fd, PRINT_NULL));
	return (write(fd, str, ft_strlen(str)));
}
