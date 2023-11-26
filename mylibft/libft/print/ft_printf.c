/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:18:09 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 13:43:34 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_printf_printptr(t_fd fd, void *ptr)
{
	int	result;

	result = 0;
	ft_print_addwrite(&result, ft_printstr(fd, PRINT_PTR_PREF));
	if (result == -1)
		return (-1);
	ft_print_addwrite(&result, ft_printnbru(fd, (t_ulong)ptr, PRINT_BASE_HXL));
	return (result);
}

static int	ft_printf_direc(t_fd fd, char **format, va_list args)
{
	int		result;

	if ((*format)[1] == 'c')
		result = ft_printchar(fd, va_arg(args, int));
	else if ((*format)[1] == 's')
		result = ft_printstr(fd, va_arg(args, char *));
	else if ((*format)[1] == 'd' || (*format)[1] == 'i')
		result = ft_printnbrs(fd, va_arg(args, int), PRINT_BASE_DEC);
	else if ((*format)[1] == 'u')
		result = ft_printnbru(fd, va_arg(args, t_uint), PRINT_BASE_DEC);
	else if ((*format)[1] == 'x')
		result = ft_printnbru(fd, va_arg(args, t_uint), PRINT_BASE_HXL);
	else if ((*format)[1] == 'X')
		result = ft_printnbru(fd, va_arg(args, t_uint), PRINT_BASE_HXU);
	else if ((*format)[1] == 'p')
		result = ft_printf_printptr(fd, va_arg(args, void *));
	else if ((*format)[1] == '%')
		result = ft_printchar(fd, '%');
	else
		result = write(fd, *format, 2);
	*format += 1;
	if (**format != '\0')
		*format += 1;
	return (result);
}

static int	ft_printf_text(t_fd fd, char **format)
{
	size_t	len;
	int		result;

	len = 0;
	while ((*format)[len] != '\0' && (*format)[len] != '%')
		len++;
	result = write(fd, *format, len);
	if (result != -1)
		*format += result;
	return (result);
}

int	ft_printf(t_fd fd, char *format, ...)
{
	int		result;
	va_list	args;

	va_start(args, format);
	result = 0;
	while (result != -1 && *format != '\0')
	{
		if (*format == '%')
			ft_print_addwrite(&result, ft_printf_direc(fd, &format, args));
		else
			ft_print_addwrite(&result, ft_printf_text(fd, &format));
	}
	va_end(args);
	return (result);
}
