/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:00 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 16:54:34 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Print a character to a file descriptor
 *
 *	Arguments:
 *	- fd: the file descriptor
 *	- c: the character
 *
 *	Return value:
 *	- The number of bytes written, or -1 if write error
 */
int	ft_printchar(t_fd fd, char c)
{
	return (write(fd, &c, 1));
}
