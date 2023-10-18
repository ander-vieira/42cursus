/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:52:11 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/18 20:29:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_print {
	char	*f;
	va_list a;
	int		r;
}	t_print;

typedef struct s_direc {
	char	t;
}	t_direc;

t_direc	pf_parsedirec(t_print *print);

int ft_printf(char const *, ...);

#endif