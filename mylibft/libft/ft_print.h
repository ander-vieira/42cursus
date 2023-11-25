/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:15:51 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 17:19:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "ft_error.h"
# include "ft_types.h"

# define PRINT_NULL		"(null)"
# define PRINT_BASE_DEC	"0123456789"
# define PRINT_BASE_HXL	"0123456789abcdef"
# define PRINT_BASE_HXU	"0123456789ABCDEF"

/* Libft internal, do not use in other projects! */
void	ft_print_addwrite(int *result, ssize_t bytes_write);

int		ft_printchar(t_fd fd, char c);
int		ft_printf(t_fd fd, char *format, ...);
int		ft_printnbrs(t_fd fd, long num, char *base);
int		ft_printnbru(t_fd fd, t_ulong num, char *base);
int		ft_printstr(t_fd fd, char *str);

#endif