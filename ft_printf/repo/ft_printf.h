/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:52:11 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 14:35:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define BASE_DEC	"0123456789"
# define BASE_HEXL	"0123456789abcdef"
# define BASE_HEXU	"0123456789ABCDEF"
# define STR_NULL	"(null)"
# define PTR_NULL	"(nil)"
# define PRE_HEXL	"0x"
# define PRE_HEXU	"0X"

# define FLAG_ALTER	0x01
# define FLAG_MINUS 0x02
# define FLAG_SPACE 0x04

typedef unsigned char	t_flag;

typedef struct s_print {
	char	*s;
	va_list	a;
	int		r;
}	t_print;

typedef struct s_direc {
	t_flag	f;
	char	t;
}	t_direc;

size_t	pf_strlen(char *str);

void	pf_write(void *buf, size_t len, t_print *print);
void	pf_putchar(char c, t_print *print);
void	pf_putstr(char *str, t_print *print);
void	pf_putnbr(long num, char *base, t_print *print);
void	pf_putunbr(unsigned long num, char *base, t_print *print);

t_direc	pf_parsedirec(t_print *print);

void	pf_printdirec(t_direc direc, t_print *print);

int		ft_printf(char const *f, ...);

#endif