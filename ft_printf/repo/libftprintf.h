/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:09:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/15 23:59:02 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

# define DIREC_START '%'
# define DIREC_FLAG ""

typedef struct s_pdata {
	char		*f;
	size_t		l;
	char		s;
}	t_pdata;

char	pf_findchar(const char *str, char c, size_t *len);
char	pf_findnotchar(const char *str, const char *charset, size_t *len);

void	pf_direc(t_pdata *pdata, size_t flags_len, va_list args);

int		ft_printf(const char *format, ...);

#endif