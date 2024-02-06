/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:24:55 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:00:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

static t_byte	*ft_error(void)
{
	static t_byte	error;

	return (&error);
}

t_byte	ft_geterror(void)
{
	return (*ft_error());
}

void	ft_seterror(t_byte error)
{
	*ft_error() = error;
}
