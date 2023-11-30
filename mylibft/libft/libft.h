/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:45 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 15:17:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */
/* Standard library includes                                                  */

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/* ************************************************************************** */
/* General use types and macros                                               */

# define FT_INT_MAX 2147483647

# define BASE_DEC	"0123456789"
# define BASE_HXL	"0123456789abcdef"
# define BASE_HXU	"0123456789ABCDEF"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
typedef int				t_fd;

/* ************************************************************************** */
/* Error handling functions and macros                                        */

# define ERR_OK		0
# define ERR_READ	1
# define ERR_WRITE	2
# define ERR_MALLOC	3

# define ERR_PARSENUM_BADBASE	101
# define ERR_PARSENUM_BADCHAR	102
# define ERR_PARSENUM_OVERFLOW	103

# define ERR_GNL_BADFD	101

typedef unsigned char	t_error;

void	ft_seterror(t_error *error, t_error value);

/* ************************************************************************** */
/* misc: Miscellaneous functions                                              */

t_ulong	ft_abs(long num);
void	ft_free(void *ptr);
t_bool	ft_isspace(char c);
void	ft_memcpy(void *dst, void *src, size_t len);
int		ft_parsenum(char *str, char *base, t_error *error);

/* ************************************************************************** */
/* str: Functions for handling strings                                        */

char	*ft_strbuild(char c, size_t len);
ssize_t	ft_strchr(char *str, char c);
t_bool	ft_strcmp(char *str1, char *str2);
char	*ft_strformat(char *format, ...);
char	*ft_strjoin(size_t n, ...);
size_t	ft_strlen(char *str);
char	*ft_strnbrs(long num, char *base);
char	*ft_strnbru(t_ulong num, char *base);
t_bool	ft_strprefix(char *str, char *prefix);
ssize_t	ft_strrchr(char *str, char c);
char	*ft_strsub(char *str, size_t len);

/* ************************************************************************** */
/* path: Functions for handling pathnames                                     */

# define PATH_DELIM 	'/'
# define PATH_CURRENT	"."
# define PATH_ROOT		"/"

char	*ft_basename(char *name);
char	*ft_dirname(char *name);
char	*ft_trimname(char *name);

/* ************************************************************************** */
/* gnl: Get next line                                                         */

# define GNL_FDLIMIT	4096
# define GNL_BUFSIZE	64

char	*ft_gnl(t_fd fd, t_error *error);

/* ************************************************************************** */
/* print: Print functions                                                     */

# define PRINT_NULL		"(null)"
# define PRINT_PTR_PREF	"0x"

void	ft_print_addwrite(int *result, ssize_t bytes_write);

int		ft_printchar(t_fd fd, char c);
int		ft_printf(t_fd fd, char *format, ...);
int		ft_printnbrs(t_fd fd, long num, char *base);
int		ft_printnbru(t_fd fd, t_ulong num, char *base);
int		ft_printstr(t_fd fd, char *str);

#endif