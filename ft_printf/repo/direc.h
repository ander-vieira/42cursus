/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:49:54 by ander             #+#    #+#             */
/*   Updated: 2023/09/15 01:54:44 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIREC_H
# define DIREC_H

# define DIREC_START "%"
# define DIREC_FLAG ""
# define DIREC_FLAG_NUM 0
# define DIREC_END "cspdiuxX%"

typedef struct s_direc {
	char	s;
	char	*flags;
	char	e;
}	t_direc;

typedef struct s_format {
	ssize_t	n;
	char	**s;
	char	**d;
}	t_format;

#endif