/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:04:30 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 16:17:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# define ERR_OK		0
# define ERR_READ	1
# define ERR_WRITE	2
# define ERR_MALLOC	3

# define ERR_PARSENUM_BADBASE	101
# define ERR_PARSENUM_BADCHAR	102
# define ERR_PARSENUM_OVERFLOW	103

# define ERR_GNL_BADFD	101

typedef unsigned char	t_error;

#endif