/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:11:39 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 16:13:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include "ft_error.h"
# include "ft_types.h"

# define GNL_FDLIMIT	4096
# define GNL_BUFSIZE	64

char	*ft_gnl(t_fd fd, t_error *error);

#endif