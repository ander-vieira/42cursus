/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:45 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 15:45:17 by andeviei         ###   ########.fr       */
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

# define BASE_BIN	"01"
# define BASE_OCT	"01234567"
# define BASE_DEC	"0123456789"
# define BASE_HXL	"0123456789abcdef"
# define BASE_HXU	"0123456789ABCDEF"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;
typedef unsigned char	t_byte;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef int				t_fd;

typedef t_bool			(*t_splitfun)(char, void *);

/* ************************************************************************** */
/* error: handling libft internal errors                                      */

# define FTERR_OK		0
# define FTERR_READ		1
# define FTERR_WRITE	2
# define FTERR_MALLOC	3
# define FTERR_BADFD	4

# define FTERR_PARSENUM_BADBASE		101
# define FTERR_PARSENUM_BADCHAR		102
# define FTERR_PARSENUM_OVERFLOW	103

t_byte	ft_geterror(void);

/* ************************************************************************** */
/* misc: Miscellaneous functions                                              */

t_ulong	ft_abs(long num);
t_bool	ft_isspace(char c);
void	ft_memcpy(void *dst, void *src, size_t len);
int		ft_parsenum(char *str, char *base);

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
t_bool	ft_strsuffix(char *str, char *suffix);
char	**ft_strsplit(char *str, char c);
char	**ft_strsplit_magic(char *str, t_splitfun fun, void *ctx);
void	ft_strsplit_free(char **split);

/* ************************************************************************** */
/* path: Functions for handling pathnames                                     */

# define PATH_DELIM 	'/'
# define PATH_CURRENT	"."
# define PATH_ROOT		"/"

char	*ft_basename(char *name);
char	*ft_dirname(char *name);
char	*ft_trimname(char *name);

/* ************************************************************************** */
/* read: Read from file descriptors                                           */

# define READ_FDLIMIT	4096
# define READ_BUFSIZE	64

char	*ft_readline(t_fd fd);
char	*ft_readfull(t_fd fd);

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