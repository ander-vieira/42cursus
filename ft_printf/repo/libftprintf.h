/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:09:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/23 18:35:00 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

# define BASE_DEC	"0123456789"
# define BASE_HEX_U	"0123456789ABCDEF"
# define BASE_HEX_L	"0123456789abcdef"

# define FLAG_LEFT	0x01
# define FLAG_ZERO	0x02
# define FLAG_PREC	0x04
# define FLAG_ALTER	0x08
# define FLAG_BLANK	0x10
# define FLAG_SIGN	0x20

typedef struct s_pdata {
	char		*f;
	size_t		l;
	char		s;
}	t_pdata;

typedef struct s_pdirec {
	unsigned char	f;
	char			t;
}	t_pdirec;

ssize_t	pf_putchar(char c);
ssize_t	pf_putstr(char *str);
ssize_t	pf_putsign(int num);
ssize_t	pf_putnbr_base(long num, char *base);

void	pf_parseflags(t_pdirec *direc, t_pdata *pdata);
void	pf_direc(t_pdirec direc, t_pdata *pdata, va_list args);

int		ft_printf(const char *format, ...);

#endif