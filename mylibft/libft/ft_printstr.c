/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 16:45:32 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(t_fd fd, char *str)
{
	if (str == NULL)
		return (ft_printstr(fd, PRINT_NULL));
	return (write(fd, str, ft_strlen(str)));
}
