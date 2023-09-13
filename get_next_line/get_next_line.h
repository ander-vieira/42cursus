/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:19 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/13 10:08:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>

typedef unsigned char	t_byte;

void	gnl_memcpy(char *dest, char *src, ssize_t size);

char	*get_next_line(int fd);

#endif