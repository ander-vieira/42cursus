/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:09:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 19:17:24 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

# define BASE_OCT	"01234567"
# define BASE_DEC	"0123456789"
# define BASE_HEX	"0123456789abcdef"

# define PREFIX_OCT	"0"
# define PREFIX_HEX	"0x"
# define PTR_NULL	"(nil)"

# define FLAG_LEFT	0x01
# define FLAG_ZERO	0x02
# define FLAG_ALTER	0x04
# define FLAG_BLANK	0x08
# define FLAG_SIGN	0x10
# define FLAG_PREC	0x20

typedef unsigned char	t_flag;

typedef struct s_pdata {
	char		*f;
	size_t		l;
	char		s;
}	t_pdata;

typedef struct s_pdirec {
	t_flag	f;
	int		w;
	int		p;
	char	t;
}	t_direc;

size_t	pf_strlen(char *str);
void	pf_strfree(char *str);
void	pf_strcpy(char *dest, char *src);
char	*pf_strdup(char *str);
char	*pf_strjoin(char *str1, char *str2);
char	*pf_strfill(char c, size_t len);
char	*pf_strupper(char *str);
char	*pf_strsign(long num, t_flag flags);
char	*pf_strnum(long num, char *base, int min);
int		pf_strreadint(char **str);
char	*pf_strpad(char *str, t_direc direc);
char	*pf_strcut(char *str, int len);

void	pf_parsedirec(t_direc *direc, t_pdata *pdata);
void	pf_printdirec(t_direc direc, t_pdata *pdata, va_list args);

int		ft_printf(const char *format, ...);

#endif