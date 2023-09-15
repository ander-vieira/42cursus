/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:58:12 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/15 14:58:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include <stdlib.h>
# include "direc.h"

typedef struct s_format {
	ssize_t	n;
	char	**s;
	t_direc	**d;
}	t_format;

void		free_format(t_format *format);
t_format	*parse_format(char *str);

#endif