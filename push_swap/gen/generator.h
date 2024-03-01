/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:14:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 01:44:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# include <stdlib.h>
# include <time.h>

# include "libft/libft.h"

# define RANGE_MULT	5

typedef struct s_gen
{
	size_t	n;
	int		*a;
	size_t	i;
	int		m;
	int		r;
}	t_gen;

#endif