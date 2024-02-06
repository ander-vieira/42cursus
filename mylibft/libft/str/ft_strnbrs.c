/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:08:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

char	*ft_strnbrs(long num, char *base)
{
	char	*result;
	char	*resultu;
	char	*sign;

	if (num < 0)
	{
		sign = ft_strbuild('-', 1);
		resultu = ft_strnbru(ft_abs(num), base);
		result = ft_strjoin(2, sign, resultu);
		return (free(sign), free(resultu), result);
	}
	else
		return (ft_strnbru(ft_abs(num), base));
}
