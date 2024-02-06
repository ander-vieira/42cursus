/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:52:17 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

static char	*ft_strformat_joinstr(char *old, char *add)
{
	char	*new;

	if (add == NULL)
		return (free(old), NULL);
	new = ft_strjoin(2, old, add);
	return (free(old), free(add), new);
}

static char	*ft_strformat_conv(char **format, va_list args)
{
	char	*result;

	if ((*format)[1] == 'c')
		result = ft_strbuild(va_arg(args, int), 1);
	else if ((*format)[1] == 's')
		result = ft_strjoin(1, va_arg(args, char *));
	else if ((*format)[1] == 'd' || (*format)[1] == 'i')
		result = ft_strnbrs(va_arg(args, int), BASE_DEC);
	else if ((*format)[1] == 'u')
		result = ft_strnbru(va_arg(args, t_uint), BASE_DEC);
	else if ((*format)[1] == 'x')
		result = ft_strnbru(va_arg(args, t_uint), BASE_HXL);
	else if ((*format)[1] == 'X')
		result = ft_strnbru(va_arg(args, t_uint), BASE_HXU);
	else if ((*format)[1] == 'p')
		result = ft_strjoin(2, PRINT_PTR_PREF, va_arg(args, void *));
	else if ((*format)[1] == '%')
		result = ft_strbuild('%', 1);
	else
		result = ft_strsub(*format, 2);
	*format += 1;
	if (**format != '\0')
		*format += 1;
	return (result);
}

static char	*ft_strformat_text(char **format)
{
	char	*result;
	size_t	len;

	len = 0;
	while ((*format)[len] != '\0' && (*format)[len] != '%')
		len++;
	result = ft_strsub(*format, len);
	*format += len;
	return (result);
}

char	*ft_strformat(char *format, ...)
{
	char	*result;
	va_list	args;

	va_start(args, format);
	result = ft_strbuild(' ', 0);
	if (result == NULL)
		return (NULL);
	while (result != NULL && *format != '\0')
	{
		if (*format == '%')
			result = ft_strformat_joinstr(result,
					ft_strformat_conv(&format, args));
		else
			result = ft_strformat_joinstr(result,
					ft_strformat_text(&format));
	}
	va_end(args);
	return (result);
}
