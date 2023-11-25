/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addwrite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:05:00 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 17:19:38 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_addwrite(int *result, ssize_t bytes_write)
{
	if (bytes_write == -1)
		*result = -1;
	else
		*result += bytes_write;
}
