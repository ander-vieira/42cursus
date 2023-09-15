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

# include <stdlib.h>

# define DIREC_START "%"
# define DIREC_FLAG ""
# define DIREC_END "cspdiuxX%"

typedef struct s_direc {
	char	*flags;
	char	end;
}	t_direc;

void	free_direc(t_direc *direc, ssize_t len);
char	parse_direc(t_direc *direc, char *str, ssize_t *pos);

#endif