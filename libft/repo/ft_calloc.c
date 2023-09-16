/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:05:35 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:44:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		total_size;
	void		*result;

	total_size = count * size;
	result = malloc(total_size);
	if (result != NULL)
		ft_bzero(result, total_size);
	return (result);
}
