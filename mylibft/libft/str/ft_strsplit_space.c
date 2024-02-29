/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:31:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/16 15:34:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

static t_bool	ft_strsplit_isspace(char c, void *ctx)
{
	(void)ctx;
	return (ft_isspace(c));
}

char	**ft_strsplit_space(char *str)
{
	return (ft_strsplit_magic(str, &ft_strsplit_isspace, NULL));
}
