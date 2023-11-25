/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:45 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 17:24:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "ft_error.h"
# include "ft_gnl.h"
# include "ft_print.h"
# include "ft_types.h"

t_ulong	ft_abs(long num);
void	ft_free(void *ptr);
t_bool	ft_isspace(char c);
void	ft_memcpy(void *dst, void *src, size_t len);
int		ft_parsenum(char *str, char *base, t_error *error);
void	ft_seterror(t_error *error, t_error value);
ssize_t	ft_strchr(char *str, char c);
t_bool	ft_strcmp(char *str1, char *str2);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlen(char *str);
t_bool	ft_strprefix(char *str, char *prefix);

#endif