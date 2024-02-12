/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:31:41 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/12 19:26:58 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INT_H
# define LIBFT_INT_H

# define FT_INT_INTMAX 2147483647

/* ************************************************************************** */
/* error: handling libft internal errors                                      */

void	ft_seterror(t_byte error);

/* ************************************************************************** */
/* print: Print functions                                                     */

void	ft_print_addwrite(int *result, ssize_t bytes_write);
int		ft_printchar(t_fd fd, char c);
int		ft_printnbrs(t_fd fd, long num, char *base);
int		ft_printnbru(t_fd fd, t_ulong num, char *base);
int		ft_printstr(t_fd fd, char *str);

#endif