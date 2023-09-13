/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:19 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/13 17:36:44 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

void	gnl_memcpy(char *dest, char *src, ssize_t size);
ssize_t	find_newline(char *buffer, ssize_t chunk_len);

char	*get_next_line(int fd);

#endif